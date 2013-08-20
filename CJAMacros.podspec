Pod::Spec.new do |spec|
  spec.name = 'CJAMacros'
  spec.version = '0.1.0'
  spec.authors = {'Carl Jahn' => 'jahncarl@gmail.com'}
  spec.homepage = 'https://https://github.com/carlj/CJAMacros'
  spec.summary = 'Collection of daily used Macros in my iOS Projects'
  spec.source = {:git => 'https://github.com/carlj/CJAMacros.git', :tag => "v#{spec.version}"}
  spec.license = { :type => 'MIT', :file => 'LICENSE' }

  spec.platform = :ios
  spec.requires_arc = true
  spec.source_files = 'CJAMacros'
end