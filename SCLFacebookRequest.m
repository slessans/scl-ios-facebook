//
//  SCLFacebookRequest.m
//  SCL IOS Components
//
//  Created by Scott Lessans on 8/28/13.
//  Copyright (c) 2013 Scott Lessans. All rights reserved.
//

#import "SCLFacebookRequest.h"

@implementation SCLFacebookRequest

- (NSString *) jsonDataString
{
    if ( ! self.jsonData ) return nil;
    
    NSError * error = nil;
    NSData * jsonData = [NSJSONSerialization dataWithJSONObject:self.jsonData
                                                        options:0
                                                          error:&error];
    if ( error ) {
        NSLog(@"Error serializing json object %@ into data %@",
              self.jsonData, error);
        return nil;
    }

    return [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
}

@end
