package main

/*
#cgo CFLAGS: -I.
#cgo LDFLAGS: -L. -lmylib
#include <stdio.h>
#include <stdlib.h>
#include "mylibGo.h"
*/
import "C"
import (
	"fmt"
	"unsafe"
)

var EXTENSION_DIR string = "./"
var OIDB_API string = "cw_mutil_thread_feature_extract.dll"

func Hello() {
	libPathC := C.CString(EXTENSION_DIR + OIDB_API)
	defer C.free(unsafe.Pointer(libPathC))
	var n C.longlong
	var test C.Mylib_cGO_test
	test.stringY = C.mylib_get_char_buf(100)
	test.pCharZ = C.mylib_get_char_buf(100)

	C.mylib_get_version(n, libPathC)
	C.mylib_cGO_test(&test)

	fmt.Println("test.intX=", test.intX)
	fmt.Println("test.size_stringY=", test.size_stringY)
	fmt.Print("test.stringY=%s", test.stringY)

}
func main() {
	Hello()
}
