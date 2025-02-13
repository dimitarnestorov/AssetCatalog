import AppKit

class AppDelegate: NSObject, NSApplicationDelegate {
    let nibOwner = Playground()
    let windowController: NSWindowController
    
    override init() {
        let bundle = Bundle(url: Bundle.main.bundleURL.appendingPathComponent("AssetCatalog_AssetCatalog Playground.bundle"))!
        
        windowController = NSWindowController(windowNibPath: bundle.path(forResource: "Window", ofType: "nib")!, owner: nibOwner)
        
        super.init()
    }
    
    func applicationDidFinishLaunching(_ notification: Notification) {
        windowController.showWindow(self)
        NSApplication.shared.activate(ignoringOtherApps: true)
    }
}
