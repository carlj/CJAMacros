//
//  CJAMacros.h
//  CJAMacros
//
//  Created by Carl Jahn
//  Copyright (c) 2013 Carl Jahn. All rights reserved.
//


#import "CJAMacros.h"


void ErrorLog(NSString *format, ...){
#if ELog 
  va_list ap;
	
	va_start(ap,format);
  
  NSLogv(format, ap);
	va_end(ap);
#endif
}
