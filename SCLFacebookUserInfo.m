//
//  SCLFacebookUserInfo.m
//  SCL IOS Components
//
//  Created by Scott Lessans on 8/18/13.
//  Copyright (c) 2013 Scott Lessans. All rights reserved.
//

#import "SCLFacebookUserInfo.h"
#import "SCLFacebookUserInfo+Protected.h"

@interface SCLFacebookUserInfo ()

@property (nonatomic, strong) NSString * facebookUserId;
@property (nonatomic, strong) NSString * location;
@property (nonatomic, strong) NSString * hometown;
@property (nonatomic, strong) NSString * email;
@property (nonatomic, strong) NSString * firstName;
@property (nonatomic, strong) NSString * middleName;
@property (nonatomic, strong) NSString * lastName;
@property (nonatomic, strong) NSString * link;
@property (nonatomic, strong) NSString * username;
@property (nonatomic, strong) NSDate * birthday;

@end

@implementation SCLFacebookUserInfo
@end

@implementation SCLFacebookUserInfo (Protected)

@dynamic facebookUserId;
@dynamic location;
@dynamic hometown;
@dynamic email;
@dynamic firstName;
@dynamic middleName;
@dynamic lastName;
@dynamic link;
@dynamic username;
@dynamic birthday;

@end
