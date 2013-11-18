//
//  SCLFacebookRequest.h
//  SCL IOS Components
//
//  Created by Scott Lessans on 8/28/13.
//  Copyright (c) 2013 Scott Lessans. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SCLFacebookRequest : NSObject

@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) NSString * message;
@property (nonatomic, strong) NSDictionary * jsonData;

- (NSString *) jsonDataString;

@end
