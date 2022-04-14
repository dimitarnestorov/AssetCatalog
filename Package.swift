// swift-tools-version: 5.5

import PackageDescription

let package = Package(
    name: "AssetCatalog",
    products: [
        .library(
            name: "AssetCatalog",
            targets: ["AssetCatalog"]
        ),
    ],
    targets: [
        .target(
            name: "AssetCatalog",
            path: "Sources",
            linkerSettings: [
                .linkedFramework("CoreUI"),
                .unsafeFlags(["-F/System/Library/PrivateFrameworks/"]),
            ]
        ),
        .executableTarget(
            name: "AssetCatalog Playground",
            dependencies: ["AssetCatalog"],
            path: "Playground",
            resources: [
                .process("Resources/Window.xib"),
            ]
        ),
    ]
)
