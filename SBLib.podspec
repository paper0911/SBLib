Pod::Spec.new do |s|
  s.name             = 'SBLib'
  s.version          = '0.1.1'
  s.summary          = 'A short description of SBLib.'

  s.description      = <<-DESC
                        SBLib...
                        DESC

  s.homepage         = "https://github.com/doll313/SBLib"
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'yuki.wang' => '385734069@qq.com' }
  s.source           = { :git => "https://github.com/CocoaPods/Specs", :tag => s.version.to_s }

  s.ios.deployment_target = '7.0'
  s.source_files = 'SBLib/Classes/**/*'
  s.prefix_header_file = "SBLib/Classes/SBLib-prefix.pch"


  # s.resource_bundles = {
  #   'SBLib' => ['SBLib/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'

  s.dependency 'FMDB'
  s.dependency 'MBProgressHUD'
  s.dependency 'MJRefresh'
  s.dependency 'SDWebImage'


non_arc_files = 'SBLib/Classes/STKeyChain/STKeychain.*','SBLib/Classes/Util/SBDownloadFilter.*'
s.exclude_files = non_arc_files
s.subspec 'no-arc' do |sp|
sp.source_files = non_arc_files
sp.requires_arc = false
end

end
