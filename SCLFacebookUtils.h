//
//  SCLFacebookUtils.h
//  SCL IOS Components
//
//  Created by Scott Lessans on 8/6/13.
//  Copyright (c) 2013 Scott Lessans. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SCLFacebookUserInfo.h"
#import "SCLFacebookPost.h"
#import "SCLFacebookRequest.h"

extern NSString * const SCLFacebookUtilsErrorDomain;

typedef NS_ENUM(NSInteger, SCLFacebookUtilsErrorCodes) {
    SCLFacebookUtilsErrorCodeInvalidSession
};

@class SCLFacebookUtils;
@class FBSession;

typedef NS_ENUM(NSInteger, SCLFacebookUtilsLoginState) {
    SCLFacebookUtilsLoginStateSuccess,
    SCLFacebookUtilsLoginStateAlreadyLoggedIn,
    SCLFacebookUtilsLoginStateFailed
};

typedef NS_ENUM(NSInteger, SCLFacebookUtilsPictureSize) {
    SCLFacebookUtilsPictureSizeDefault,
    SCLFacebookUtilsPictureSizeSquare = 1,
    SCLFacebookUtilsPictureSizeSmall,
    SCLFacebookUtilsPictureSizeNormal,
    SCLFacebookUtilsPictureSizeLarge
};

typedef NS_ENUM(NSInteger, SCLFacebookResult) {
    SCLFacebookResultError = 0,
    SCLFacebookResultUserCancelled = 1, // not always applicable
    SCLFacebookResultSuccess = 5
};

extern NSString * SCLFacebookUtilsStringFromPictureSize(SCLFacebookUtilsPictureSize);

typedef void (^SCLFacebookUtilsLoginBlock)(SCLFacebookUtilsLoginState result, NSError * error);
typedef void (^SCLFacebookUserInfoCallback)(SCLFacebookUserInfo * info, NSError * error);
typedef void (^SCLFacebookFriendsCallback)(NSArray * friends, NSError * error);
typedef void (^SCLPermissionRequestCallback)(BOOL permissionGranted, NSError * error);
typedef void (^SCLSendRequestCallback)(SCLFacebookRequest * request, NSArray * recipientIds, SCLFacebookResult result, NSError * error);

// if success createdPostId has id of new post, if error createdPostId is nil and error has error
typedef void (^SCLPublishPostCallback)(SCLFacebookPost * post, NSString * createdPostId, NSError * error);
typedef void (^SCLFacebookDialogCallback)(SCLFacebookResult result, NSError * error);


// dealing with friends request results
extern NSString * SCLFacebookUtilsFriendName(NSDictionary * friendData);
extern NSString * SCLFacebookUtilsFriendId(NSDictionary * friendData);
extern NSURL * SCLFacebookUtilsFriendProfilePictureUrl(NSDictionary * friendData);
extern NSURL * SCLFacebookUtilsFriendProfilePictureUrlWithSize(NSDictionary * friendData, SCLFacebookUtilsPictureSize size);


@class FBAppCall;

// IMPORTANT NOTE: any input going into a method that interacts with the facebook API
// could potentially be going into a FQL query and should be sanitized BEFORE being
// passed to these methods.
@interface SCLFacebookUtils : NSObject

@property (nonatomic, readonly) FBSession * session;
@property (nonatomic, readonly) SCLFacebookUserInfo * currentUserInfo;
@property (nonatomic, readonly) NSString * currentUserFacebookAccessToken;

#pragma mark constructing
+ (instancetype) sharedInstance;

#pragma mark methods to put in app delegate
- (void) applicationWillTerminate:(UIApplication *)application;

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation
    fallbackHandler:(void (^)(FBAppCall *))fallbackBlock;

- (void) applicationDidBecomeActive:(UIApplication *)application;


#pragma mark logging in/out user
- (void) loginUserWithBlock:(SCLFacebookUtilsLoginBlock)callback;
- (BOOL) doesHaveLoggedInUser;
- (BOOL) doesHaveCachedUser;
- (void) logoutFacebookUser;

#pragma mark profile pictures
- (NSURL *) profilePictureUrlForUserWithId:(NSString *)userId;
- (NSURL *) profilePictureUrlForUserWithId:(NSString *)userId
                                      size:(SCLFacebookUtilsPictureSize)size;

#pragma mark user info
- (void) refreshFacebookUserInfoInBackgroundWithBlock:(SCLFacebookUserInfoCallback)block;

#pragma mark friends
- (void) fetchFriendsOfCurrentUserWithBlock:(SCLFacebookFriendsCallback)block;
- (void) fetchFriendsOfUser:(NSString *)userFacebookId withBlock:(SCLFacebookFriendsCallback)block;

- (void) fetchRandomFriendsOfCurrentUserWithLimit:(NSInteger)limit
                                            block:(SCLFacebookFriendsCallback)block;
- (void) fetchRandomFriendsOfUser:(NSString *)userFacebookId
                            limit:(NSInteger)limit
                            block:(SCLFacebookFriendsCallback)block;

- (void) fetchFriendsOfCurrentUserWithSearchText:(NSString *)searchText
                                           block:(SCLFacebookFriendsCallback)block;

- (void) fetchFriendsOfUser:(NSString *)userFacebookId
                 searchText:(NSString *)searchText
                      block:(SCLFacebookFriendsCallback)block;

#pragma mark posting on the current users feed
- (BOOL) canPublishToFeedOfCurrentUser;
- (void) requestPermissionToPublishToFeedOfCurrentUserWithBlock:(SCLPermissionRequestCallback)block;
- (void) publishPostToFeedOfCurrentUser:(SCLFacebookPost *)post withCallback:(SCLPublishPostCallback)block;

#pragma mark posting to other users feeds
// WILL launch a dialod
// USER IDS should be NSString
- (void) sendRequest:(SCLFacebookRequest *)request
             toUsers:(NSArray *)userIds
        withCallback:(SCLSendRequestCallback)block;

@end



