//
//  SCLFacebookPost.h
//  SCL IOS Components
//
//  Created by Scott Lessans on 8/28/13.
//  Copyright (c) 2013 Scott Lessans. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SCLFacebookPost : NSObject

// one of the following two is required
@property (nonatomic, strong) NSString * message;
@property (nonatomic, strong) NSURL * link;

// the link* properties can only be used if link is also specified
@property (nonatomic, strong) NSURL * linkPictureUrl;
@property (nonatomic, strong) NSString * linkName;  // fb key: name
@property (nonatomic, strong) NSString * linkCaption;       // fb key: caption
@property (nonatomic, strong) NSString * linkDescription;   // fb key: description

// check if data is valid
- (BOOL) isValid;

// serializes into dictionary that can be used with facebook open graph calls
// maybe this should return nil if not valid?
- (NSDictionary *) facebookParameters;

@end
