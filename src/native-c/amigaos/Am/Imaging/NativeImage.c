#include <libc/core.h>
#include <Am/Imaging/NativeImage.h>
#include <amigaos/Am/Imaging/NativeImage.h>
#include <Am/Lang/ClassRef.h>
#include <Am/Lang/Object.h>
#include <Am/Lang/UShort.h>
#include <Am/Imaging/PixelFormat.h>
#include <Am/Lang/Byte.h>
#include <Am/Lang/Array.h>
#include <Am/Lang/UInt.h>
#include <Am/Imaging/Image.h>
#include <Am/Lang/UByte.h>
#include <Am/Lang/Bool.h>
#include <libc/core_inline_functions.h>

function_result Am_Imaging_NativeImage__native_init_0(aobject * const this)
{
	function_result __result = { .has_return_value = false };
	bool __returning = false;
	// Add reference count for this in NativeImage._native_init
	if (this != NULL) {
		__increase_reference_count(this);
	}
	// TODO: implement native function Am_Imaging_NativeImage__native_init_0
__exit: ;
	if (this != NULL) {
		__decrease_reference_count(this);
	}
	return __result;
}

function_result Am_Imaging_NativeImage__native_release_0(aobject * const this)
{
	function_result __result = { .has_return_value = false };
	bool __returning = false;
	// TODO: implement native function Am_Imaging_NativeImage__native_release_0
__exit: ;
	return __result;
}

function_result Am_Imaging_NativeImage__native_mark_children_0(aobject * const this)
{
	function_result __result = { .has_return_value = false };
	bool __returning = false;
	// TODO: implement native function Am_Imaging_NativeImage__native_mark_children_0
__exit: ;
	return __result;
}

function_result Am_Imaging_NativeImage_initFromPaletteImage_0(aobject * const this, unsigned short width, unsigned short height, int pixelFormat, aobject * pixelIndices, aobject * pixelColors)
{
	function_result __result = { .has_return_value = false };
	bool __returning = false;
	// Add reference count for this in NativeImage.initFromPaletteImage
	if (this != NULL) {
		__increase_reference_count(this);
	}
	// Add reference count for pixelFormat in NativeImage.initFromPaletteImage
	// Add reference count for pixelIndices in NativeImage.initFromPaletteImage
	if (pixelIndices != NULL) {
		__increase_reference_count(pixelIndices);
	}
	// Add reference count for pixelColors in NativeImage.initFromPaletteImage
	if (pixelColors != NULL) {
		__increase_reference_count(pixelColors);
	}
	// TODO: implement native function Am_Imaging_NativeImage_initFromPaletteImage_0
__exit: ;
	if (this != NULL) {
		__decrease_reference_count(this);
	}
	if (pixelIndices != NULL) {
		__decrease_reference_count(pixelIndices);
	}
	if (pixelColors != NULL) {
		__decrease_reference_count(pixelColors);
	}
	return __result;
}

struct BitMap *make_offscreen_cgx_bitmap(struct RastPort *friendRP,
                                         UWORD w, UWORD h)
{
    ULONG depth = GetCyberMapAttr(friendRP->BitMap, CYBRMATTR_DEPTH);

    // CGX: BMF_MINPLANES recommended; BMF_DISPLAYABLE for VRAM-eligible bitmap
    struct BitMap *bm = AllocBitMap(
        w, h, depth,
        BMF_MINPLANES | BMF_DISPLAYABLE,
        friendRP->BitMap   // friend bitmap -> match pixel format
    );
    return bm;
}

function_result Am_Imaging_NativeImage_initFromARGBImage_0(aobject * const this, unsigned short width, unsigned short height, int pixelFormat, aobject * pixelColors)
{
	function_result __result = { .has_return_value = false };
	bool __returning = false;
	// Add reference count for this in NativeImage.initFromARGBImage
	if (this != NULL) {
		__increase_reference_count(this);
	}
	// Add reference count for pixelFormat in NativeImage.initFromARGBImage
	// Add reference count for pixelColors in NativeImage.initFromARGBImage
	if (pixelColors != NULL) {
		__increase_reference_count(pixelColors);
	}
	// TODO: implement native function Am_Imaging_NativeImage_initFromARGBImage_0
    // copy the array data from pixelColors into an Amiga Bitmap using CyberGfx

    array_holder *ah = get_array_holder(pixelColors);
    ULONG *data = (ULONG *) get_array_data(ah);

    BitMap bm = AllocBitMap()
    if (bm == NULL) {
        // Handle error: could not create bitmap
        __result.exception = __create_exception(__create_string_constant("Could not create Amiga Bitmap", &__string_class_alias));
        goto __exit;
    }

    struct RastPort rp2;
    InitRastPort(&rp2);
    rp2.BitMap = myBitMap;   // truecolor RTG BitMap


    if (bm != NULL) {
        // Copy the pixel data from the pixelColors array into the Amiga Bitmap
        for (unsigned short y = 0; y < height; y++) {
            for (unsigned short x = 0; x < width; x++) {
                // Get the color from the pixelColors array
                int color = GetPixelColor(pixelColors, x, y);
                // Set the pixel color in the Amiga Bitmap
                SetPixelColor(bm, x, y, color);
            }
        }
    }

__exit: ;
	if (this != NULL) {
		__decrease_reference_count(this);
	}
	if (pixelColors != NULL) {
		__decrease_reference_count(pixelColors);
	}
	return __result;
}

