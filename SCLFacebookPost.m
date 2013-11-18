//
//  SCLFacebookPost.m
//  SCL IOS Components
//
//  Created by Scott Lessans on 8/28/13.
//  Copyright (c) 2013 Scott Lessans. All rights reserved.
//

#import "SCLFacebookPost.h"

//message	Post message	string	 either message or link
//link	Post URL	string	 either message or link

//picture	Post thumbnail image (can only be used if link is specified)	string	 no
//name	Post name (can only be used if link is specified)	string	 no
//caption	Post caption (can only be used if link is specified)	string	 no
//description	Post description (can only be used if link is specified)	string	 no

// TODO:
//actions	Post actions	array of objects containing name and link	 no
//place	 Facebook Page ID of the location associated with this Post	string	 no
//tags	 Comma-separated list of Facebook IDs of people tagged in this Post. For example: 1207059,701732. This field is returned as the with_tags field when the Post is read. NOTE: You cannot specify this field without also specifying a place.	string	 no
//privacy	Post privacy settings (can only be specified if the Timeline being posted on belongs to the User creating the Post)	string	 no
//object_attachment	 Facebook ID for an existing picture in the User's photo albums to use as the thumbnail image. The User must be the owner of the photo, and the photo cannot be part of a message attachment.	string	 no

static void addValueToDictionaryIfExists(NSMutableDictionary * dictionary,
                                         NSString * key,
                                         NSString * val)
{
    if ( ! val ) return;
    dictionary[key] = val;
}

@implementation SCLFacebookPost

- (BOOL) isValid
{
    // make sure major content is specified
    if ( ! (self.message || self.link) )
        return NO;
    
    // make sure no link properties specified, if no link
    if ( ! self.link )
    {
        if ( self.linkCaption || self.linkDescription || self.linkName || self.linkPictureUrl )
        {
            return NO;
        }
    }
    
    return YES;
}

- (NSDictionary *) facebookParameters
{
    NSMutableDictionary * params = [[NSMutableDictionary alloc] init];
    
    addValueToDictionaryIfExists(params, @"message",        self.message);
    addValueToDictionaryIfExists(params, @"picture",        [self.linkPictureUrl absoluteString]);
    addValueToDictionaryIfExists(params, @"link",           [self.link absoluteString]);
    addValueToDictionaryIfExists(params, @"name",           self.linkName);
    addValueToDictionaryIfExists(params, @"caption",        self.linkCaption);
    addValueToDictionaryIfExists(params, @"description",    self.linkDescription);
    
    return params;
}

@end
