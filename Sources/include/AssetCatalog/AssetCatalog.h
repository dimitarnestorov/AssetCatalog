#import <Cocoa/Cocoa.h>

/// The name of the asset
extern NSString *__nonnull const kACSNameKey;
/// An NSImage representing the image for the asset
extern NSString *__nonnull const kACSImageKey;
/// An NSImage representing a smaller version of the asset's image (suitable for thumbnails)
extern NSString *__nonnull const kACSThumbnailKey;
/// An NSString with the suggested filename for the asset
extern NSString *__nonnull const kACSFilenameKey;
/// An NSData containing PNG image data for the asset
extern NSString *__nonnull const kACSPNGDataKey;
/// An NSBitmapImageRep containing a bitmap representation of the asset
extern NSString *__nonnull const kACSImageRepKey;

@interface AssetCatalog : NSObject

@property (nonatomic, assign) NSSize thumbnailSize;

@property (nonatomic, strong) NSArray <NSDictionary <NSString *, NSObject *> *> *__nonnull images;
@property (nonatomic, copy) NSString *__nullable catalogName;
@property (nonatomic, copy) NSError *__nullable error;

// After reading, contains the total number of assets contained within the asset catalog
@property (readonly) NSUInteger totalNumberOfAssets;

- (instancetype __nonnull)initWithFileURL:(NSURL * __nonnull)URL;
- (void)readWithCompletionHandler:(void (^__nonnull)(void))callback progressHandler:(void (^__nullable)(double progress))progressCallback;

// Performs a more lightweight read (used by the QuickLook PlugIn)
- (void)resourceConstrainedReadWithMaxCount:(int)max completionHandler:(void (^__nonnull)(void))callback;

- (void)cancelReading;

@property (nonatomic, assign) BOOL cancelled;

@property (nonatomic, assign) BOOL distinguishCatalogsFromThemeStores;
@property (nonatomic, assign) BOOL ignorePackedAssets;


- (NSMutableArray<NSDictionary<NSString *, NSObject *> *> * _Nonnull)readImages:(NSString * _Nonnull)name distinguishCatalogsFromThemeStores:(BOOL)distinguishCatalogsFromThemeStores;

@end
