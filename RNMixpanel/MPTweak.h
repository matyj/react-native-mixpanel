//
//  MPTweak.h
//  RNMixpanel
//
//  Created by Seweryn Załupka on 02/11/2018.
//  Copyright © 2018 Davide Scalzo. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@protocol MPTweakObserver;

/**
 @abstract Represents a possible value of a tweak.
 @discussion Should be able to be persisted in user defaults.
 For minimum and maximum values, should implement -compare:.
 */
typedef id MPTweakValue;

/**
 @abstract Represents a tweak
 @discussion A tweak contains a persistent, editable value.
 */
@interface MPTweak : NSObject

/**
 @abstract Creates a new tweak model.
 @discussion This is the designated initializer.
 */
- (instancetype)initWithName:(NSString *)name andEncoding:(NSString *)encoding;

/**
 @abstract This tweak's unique name.
 @discussion Used when reading and writing the tweak's value.
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 @abstract This tweak's value encoding, as returned by `@encoding`
 */
@property (nonatomic, copy, readonly) NSString *encoding;

/**
 @abstract The default value of the tweak.
 @discussion Use this when the current value is unset.
 */
@property (nonatomic, strong, readwrite) MPTweakValue defaultValue;

/**
 @abstract The current value of the tweak. Can be nil.
 @discussion Changes to this property will be propagated to disk.
 */
@property (nullable, nonatomic, strong, readwrite) MPTweakValue currentValue;

/**
 @abstract The minimum value of the tweak.
 @discussion Optional. If nil, there is no minimum.
 */
@property (nonatomic, strong, readwrite) MPTweakValue minimumValue;

/**
 @abstract The maximum value of the tweak.
 @discussion Optional. If nil, there is no maximum.
 */
@property (nonatomic, strong, readwrite) MPTweakValue maximumValue;

/**
 @abstract Adds an observer to the tweak.
 @param observer The observer. Must not be nil.
 @discussion A weak reference is taken on the observer.
 */
- (void)addObserver:(id<MPTweakObserver>)observer;

/**
 @abstract Removes an observer from the tweak.
 @param observer The observer to remove. Must not be nil.
 @discussion Optional, removing an observer isn't required.
 */
- (void)removeObserver:(id<MPTweakObserver>)observer;

@end

/**
 @abstract Responds to updates when a tweak changes.
 */
@protocol MPTweakObserver <NSObject>

/**
 @abstract Called when a tweak's value changes.
 @param tweak The tweak which changed in value.
 */
- (void)tweakDidChange:(MPTweak *)tweak;

@end

NS_ASSUME_NONNULL_END
