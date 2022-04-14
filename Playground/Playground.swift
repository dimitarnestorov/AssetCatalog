import AppKit
import AssetCatalog

class Playground {
    
    @IBOutlet weak var imageView: NSImageView! {
        didSet {
            let catalog = AssetCatalog.init(fileURL: .init(fileURLWithPath: "/Applications/Xcode.app/Contents/Frameworks/IDEKit.framework/Versions/A/Resources/Assets.car"))
            
            let result = catalog.readImages("IDEAlertBezel_Build", distinguishCatalogsFromThemeStores: true)
            
            let image = (result[1] as! NSDictionary)["image"] as! NSImage
            image.isTemplate = true
            imageView.image = image
        }
    }
    
}
