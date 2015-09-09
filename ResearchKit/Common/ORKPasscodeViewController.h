/*
 Copyright (c) 2015, Apple Inc. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
 
 1.  Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2.  Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation and/or
 other materials provided with the distribution.
 
 3.  Neither the name of the copyright holder(s) nor the names of any contributors
 may be used to endorse or promote products derived from this software without
 specific prior written permission. No license is granted to the trademarks of
 the copyright holders even if such marks are included in this software.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#import "ORKStepViewController.h"
#import "ORKDefines.h"


NS_ASSUME_NONNULL_BEGIN

static NSString * const kPasscodeKey = @"ORKPasscode";

/**
 The passcode delegate protocol declares methods which forward the success or failure of passcode modification
 or authentication.
 */
ORK_AVAILABLE_DECL
@protocol ORKPasscodeDelegate <NSObject>

@required
/**
 Notifies the delegate that the user has finished authenticating or editing the passcode.
 
 @param viewController      The `ORKPasscodeStepViewController` object in which the passcode input is entered.
 */
- (void)passcodeViewControllerDidFinishWithSuccess:(UIViewController *)viewController;

/**
 Notifies the delegate that the user failed authentication.
 
 @param viewController      The `ORKPasscodeStepViewController` object in which the passcode input is entered.
 */
- (void)passcodeViewControllerDidFailAuthentication:(UIViewController *)viewController;

@optional
/**
 Notifies the delegate that the user hit the cancel button item. The cancel button is only visible if this method
 is implemented.
 
 @param viewController      The `ORKPasscodeStepViewController` object in which the passcode input is entered.
 */
- (void)passcodeViewControllerDidCancel:(UIViewController *)viewController;

@end


/**
 An `ORKPasscodeStepViewController` object is the view controller for an `ORKPasscodeStep` object.
 
 A passcode view controller can also be instantiated directly for authentication and editing by using one 
 of the factory methods below. Each factory method requires a delegate to be implemented.
 */
ORK_CLASS_AVAILABLE
@interface ORKPasscodeViewController : UINavigationController

+ (id)passcodeAuthenticationViewControllerWithText:(nullable NSString *)text
                                      passcodeType:(ORKPasscodeType)passcodeType
                                          delegate:(id<ORKPasscodeDelegate>)delegate
                              useTouchIdIfAvaiable:(BOOL)useTouchId;

+ (id)passcodeEditingViewControllerWithText:(nullable NSString *)text
                               passcodeType:(ORKPasscodeType)passcodeType
                                   delegate:(id<ORKPasscodeDelegate>)delegate
                       useTouchIdIfAvaiable:(BOOL)useTouchId;

@end

NS_ASSUME_NONNULL_END
