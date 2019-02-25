//
// Created by mmackowiak on 09.10.2015.
// Copyright (c) 2015 CTM Mobiltek. All rights reserved.
//

#import "AdditionalInfo.h"


@implementation AdditionalInfo

- (void) encodeWithCoder:(NSCoder *)aCoder{
    [aCoder encodeObject:self.key forKey:@"key"];
    [aCoder encodeObject:self.value forKey:@"value"];
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder{
    self = [super init];
    if (self) {
        self.key = [aDecoder decodeObjectForKey:@"key"];
        self.value = [aDecoder decodeObjectForKey:@"value"];
    }
   
    return self;
}

@end