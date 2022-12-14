//
//  CoreSVG.h
//  
//
//  Created by Serena on 29/10/2022
//
	

#define HAS_UIKIT __has_include(<UIKit/UIKit.h>)

#if HAS_UIKIT
@import UIKit;
#else
@import CoreGraphics;
#endif

#ifndef CoreSVG_h
#define CoreSVG_h

struct CGSVGDocument;

typedef struct CGSVGDocument *CGSVGDocumentRef;

CGSVGDocumentRef CGSVGDocumentCreateFromData(CFDataRef, CFDictionaryRef);
void CGContextDrawSVGDocument(CGContextRef, CGSVGDocumentRef);
CGSize CGSVGDocumentGetCanvasSize(CGSVGDocumentRef);

CGSVGDocumentRef CGSVGDocumentRetain(struct CGSVGDocument);
void CGSVGDocumentRelease(CGSVGDocumentRef);

#if HAS_UIKIT
// UIImage init from a SVG doc
@interface UIImage (CoreSVGPrivate)
+(instancetype)_imageWithCGSVGDocument:(struct CGSVGDocument *)arg0 scale:(CGFloat)arg1 orientation:(NSInteger)arg2;
-(IOSurfaceRef)_copyIOSurface;
@end
#endif

#endif /* CoreSVG_h */
