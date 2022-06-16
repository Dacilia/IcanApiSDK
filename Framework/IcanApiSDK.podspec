Pod::Spec.new do |spec|
  spec.name         = "IcanApiSDK"#SDK名称
  spec.version      = "1.0.0"#版本号
  spec.summary      = "GMUnite for gama games developer."#概要
#描述  （描述一定要比概要多一些,不然会有警告!）
  spec.description  = <<-DESC
    GMUnite for gama games developer.GMUnite for gama games developer.
                   DESC
  spec.homepage     = "https://github.com/Dacilia/IcanApiSDK.git"#github 上的仓库地址
  spec.license      = { :type => "MIT", :file => "LICENSE" }#创建GitHub仓库时使用的license类型
  spec.author             = { "MWS" => "18824676521@163.com" }#作者
  spec.platform     = :ios#支持平台
  spec.ios.deployment_target = "8.0"#支持iOS最低版本
  spec.source       = { :git => "https://github.com/Dacilia/IcanApiSDK.git", :tag => "#{spec.version}" }
  #spec.resource = "Framework/GMGSupport.bundle"#资源相对于本文件本地路径
  spec.ios.vendored_frameworks = 'Framework/IcanApiSDK.framework'#SDK相对本文件路径
  spec.frameworks = "UIKit", "Foundation"#SDK依赖的系统库文件
  # spec.library   = "iconv"
  # spec.libraries = "iconv", "xml2"
  spec.requires_arc = true#是否时自动内存管理
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64'}#支持架构配置
  #spec.dependency "Reachability"#依赖的第三方库1
  #spec.dependency "Masonry"#依赖的第三方库2
end
