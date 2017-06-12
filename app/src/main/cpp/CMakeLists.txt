# 打印语句
# message([SEND_ERROR | STATUS | FATAL_ERROR] message to display ...)
# 批量指定源文件
# file(GLOB_RECURSE pdfium_core_src ${SRC_HOME_PATH}/core/*.cpp)

cmake_minimum_required(VERSION 3.4.1)

message(STATUS ===cmake start===)

set(SRC_HOME_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS src dir : ${SRC_HOME_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -fexceptions -frtti")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DHAVE_PTHREADS")

# 指定头文件目录
include_directories(
    ${SRC_HOME_PATH}
    ${SRC_HOME_PATH}/third_party/freetype/include
    ${SRC_HOME_PATH}/third_party/freetype/include/freetype)

add_library(fdrm STATIC
    core/include/fdrm/fx_crypt.h
    core/src/fdrm/crypto/fx_crypt.cpp
    core/src/fdrm/crypto/fx_crypt_aes.cpp
    core/src/fdrm/crypto/fx_crypt_sha.cpp)

add_library(fpdfdoc STATIC
    core/include/fpdfdoc/fpdf_ap.h
    core/include/fpdfdoc/fpdf_doc.h
    core/include/fpdfdoc/fpdf_tagged.h
    core/include/fpdfdoc/fpdf_vt.h
    core/src/fpdfdoc/doc_action.cpp
    core/src/fpdfdoc/doc_annot.cpp
    core/src/fpdfdoc/doc_ap.cpp
    core/src/fpdfdoc/doc_basic.cpp
    core/src/fpdfdoc/doc_bookmark.cpp
    core/src/fpdfdoc/doc_form.cpp
    core/src/fpdfdoc/doc_formcontrol.cpp
    core/src/fpdfdoc/doc_formfield.cpp
    core/src/fpdfdoc/doc_link.cpp
    core/src/fpdfdoc/doc_metadata.cpp
    core/src/fpdfdoc/doc_ocg.cpp
    core/src/fpdfdoc/doc_tagged.cpp
    core/src/fpdfdoc/doc_utils.cpp
    core/src/fpdfdoc/doc_utils.h
    core/src/fpdfdoc/doc_viewerPreferences.cpp
    core/src/fpdfdoc/doc_vt.cpp
    core/src/fpdfdoc/doc_vtmodule.cpp
    core/src/fpdfdoc/pdf_vt.h
    core/src/fpdfdoc/tagged_int.h)

add_library(fpdfapi STATIC
    core/include/fpdfapi/fpdf_module.h
    core/include/fpdfapi/fpdf_objects.h
    core/include/fpdfapi/fpdf_page.h
    core/include/fpdfapi/fpdf_pageobj.h
    core/include/fpdfapi/fpdf_parser.h
    core/include/fpdfapi/fpdf_render.h
    core/include/fpdfapi/fpdf_resource.h
    core/include/fpdfapi/fpdf_serial.h
    core/src/fpdfapi/fpdf_basic_module.cpp
    core/src/fpdfapi/fpdf_cmaps/cmap_int.h
    core/src/fpdfapi/fpdf_cmaps/CNS1/Adobe-CNS1-UCS2_5.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/B5pc-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/B5pc-V_0.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/cmaps_cns1.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/CNS-EUC-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/CNS-EUC-V_0.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/ETen-B5-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/ETen-B5-V_0.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/ETenms-B5-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/ETenms-B5-V_0.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/HKscs-B5-H_5.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/HKscs-B5-V_5.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/UniCNS-UCS2-H_3.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/UniCNS-UCS2-V_3.cpp
    core/src/fpdfapi/fpdf_cmaps/CNS1/UniCNS-UTF16-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/fpdf_cmaps.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/Adobe-GB1-UCS2_5.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/cmaps_gb1.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GB-EUC-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GB-EUC-V_0.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GBK-EUC-H_2.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GBK-EUC-V_2.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GBK2K-H_5.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GBK2K-V_5.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GBKp-EUC-H_2.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GBKp-EUC-V_2.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GBpc-EUC-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/GBpc-EUC-V_0.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/UniGB-UCS2-H_4.cpp
    core/src/fpdfapi/fpdf_cmaps/GB1/UniGB-UCS2-V_4.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/83pv-RKSJ-H_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/90ms-RKSJ-H_2.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/90ms-RKSJ-V_2.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/90msp-RKSJ-H_2.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/90msp-RKSJ-V_2.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/90pv-RKSJ-H_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/Add-RKSJ-H_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/Add-RKSJ-V_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/Adobe-Japan1-UCS2_4.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/cmaps_japan1.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/EUC-H_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/EUC-V_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/Ext-RKSJ-H_2.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/Ext-RKSJ-V_2.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/H_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/UniJIS-UCS2-HW-H_4.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/UniJIS-UCS2-HW-V_4.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/UniJIS-UCS2-H_4.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/UniJIS-UCS2-V_4.cpp
    core/src/fpdfapi/fpdf_cmaps/Japan1/V_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/Adobe-Korea1-UCS2_2.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/cmaps_korea1.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/KSC-EUC-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/KSC-EUC-V_0.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/KSCms-UHC-HW-H_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/KSCms-UHC-HW-V_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/KSCms-UHC-H_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/KSCms-UHC-V_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/KSCpc-EUC-H_0.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/UniKS-UCS2-H_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/UniKS-UCS2-V_1.cpp
    core/src/fpdfapi/fpdf_cmaps/Korea1/UniKS-UTF16-H_0.cpp
    core/src/fpdfapi/fpdf_edit/editint.h
    core/src/fpdfapi/fpdf_edit/fpdf_edit_content.cpp
    core/src/fpdfapi/fpdf_edit/fpdf_edit_create.cpp
    core/src/fpdfapi/fpdf_edit/fpdf_edit_doc.cpp
    core/src/fpdfapi/fpdf_edit/fpdf_edit_image.cpp
    core/src/fpdfapi/fpdf_font/font_int.h
    core/src/fpdfapi/fpdf_font/fpdf_font.cpp
    core/src/fpdfapi/fpdf_font/fpdf_font_charset.cpp
    core/src/fpdfapi/fpdf_font/fpdf_font_cid.cpp
    core/src/fpdfapi/fpdf_font/ttgsubtable.cpp
    core/src/fpdfapi/fpdf_font/ttgsubtable.h
    core/src/fpdfapi/fpdf_page/fpdf_page.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_colors.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_doc.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_func.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_graph_state.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_image.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_parser.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_parser_old.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_path.cpp
    core/src/fpdfapi/fpdf_page/fpdf_page_pattern.cpp
    core/src/fpdfapi/fpdf_page/pageint.h
    core/src/fpdfapi/fpdf_parser/fpdf_parser_decode.cpp
    core/src/fpdfapi/fpdf_parser/fpdf_parser_document.cpp
    core/src/fpdfapi/fpdf_parser/fpdf_parser_encrypt.cpp
    core/src/fpdfapi/fpdf_parser/fpdf_parser_fdf.cpp
    core/src/fpdfapi/fpdf_parser/fpdf_parser_objects.cpp
    core/src/fpdfapi/fpdf_parser/fpdf_parser_parser.cpp
    core/src/fpdfapi/fpdf_parser/fpdf_parser_utility.cpp
    core/src/fpdfapi/fpdf_parser/parser_int.h
    core/src/fpdfapi/fpdf_render/fpdf_render.cpp
    core/src/fpdfapi/fpdf_render/fpdf_render_cache.cpp
    core/src/fpdfapi/fpdf_render/fpdf_render_image.cpp
    core/src/fpdfapi/fpdf_render/fpdf_render_loadimage.cpp
    core/src/fpdfapi/fpdf_render/fpdf_render_pattern.cpp
    core/src/fpdfapi/fpdf_render/fpdf_render_text.cpp
    core/src/fpdfapi/fpdf_render/render_int.h)

add_library(fpdftext STATIC
    core/include/fpdftext/fpdf_text.h
    core/src/fpdftext/fpdf_text.cpp
    core/src/fpdftext/fpdf_text_int.cpp
    core/src/fpdftext/fpdf_text_search.cpp
    core/src/fpdftext/text_int.h
    core/src/fpdftext/txtproc.h
    core/src/fpdftext/unicodenormalization.cpp
    core/src/fpdftext/unicodenormalizationdata.cpp
    core/src/fpdftext/unicodenormalizationdata.h)


add_library(libjpeg STATIC
    third_party/libjpeg/cderror.h
    third_party/libjpeg/cdjpeg.h
    third_party/libjpeg/fpdfapi_jcapimin.c
    third_party/libjpeg/fpdfapi_jcapistd.c
    third_party/libjpeg/fpdfapi_jccoefct.c
    third_party/libjpeg/fpdfapi_jccolor.c
    third_party/libjpeg/fpdfapi_jcdctmgr.c
    third_party/libjpeg/fpdfapi_jchuff.c
    third_party/libjpeg/fpdfapi_jcinit.c
    third_party/libjpeg/fpdfapi_jcmainct.c
    third_party/libjpeg/fpdfapi_jcmarker.c
    third_party/libjpeg/fpdfapi_jcmaster.c
    third_party/libjpeg/fpdfapi_jcomapi.c
    third_party/libjpeg/fpdfapi_jcparam.c
    third_party/libjpeg/fpdfapi_jcphuff.c
    third_party/libjpeg/fpdfapi_jcprepct.c
    third_party/libjpeg/fpdfapi_jcsample.c
    third_party/libjpeg/fpdfapi_jctrans.c
    third_party/libjpeg/fpdfapi_jdapimin.c
    third_party/libjpeg/fpdfapi_jdapistd.c
    third_party/libjpeg/fpdfapi_jdcoefct.c
    third_party/libjpeg/fpdfapi_jdcolor.c
    third_party/libjpeg/fpdfapi_jddctmgr.c
    third_party/libjpeg/fpdfapi_jdhuff.c
    third_party/libjpeg/fpdfapi_jdinput.c
    third_party/libjpeg/fpdfapi_jdmainct.c
    third_party/libjpeg/fpdfapi_jdmarker.c
    third_party/libjpeg/fpdfapi_jdmaster.c
    third_party/libjpeg/fpdfapi_jdmerge.c
    third_party/libjpeg/fpdfapi_jdphuff.c
    third_party/libjpeg/fpdfapi_jdpostct.c
    third_party/libjpeg/fpdfapi_jdsample.c
    third_party/libjpeg/fpdfapi_jdtrans.c
    third_party/libjpeg/fpdfapi_jerror.c
    third_party/libjpeg/fpdfapi_jfdctfst.c
    third_party/libjpeg/fpdfapi_jfdctint.c
    third_party/libjpeg/fpdfapi_jidctfst.c
    third_party/libjpeg/fpdfapi_jidctint.c
    third_party/libjpeg/fpdfapi_jidctred.c
    third_party/libjpeg/fpdfapi_jmemmgr.c
    third_party/libjpeg/fpdfapi_jmemnobs.c
    third_party/libjpeg/fpdfapi_jutils.c
    third_party/libjpeg/jchuff.h
    third_party/libjpeg/jconfig.h
    third_party/libjpeg/jdct.h
    third_party/libjpeg/jdhuff.h
    third_party/libjpeg/jerror.h
    third_party/libjpeg/jinclude.h
    third_party/libjpeg/jmemsys.h
    third_party/libjpeg/jmorecfg.h
    third_party/libjpeg/jpegint.h
    third_party/libjpeg/jpeglib.h
    third_party/libjpeg/jversion.h
    third_party/libjpeg/transupp.h)


add_library(fx_lcms2 STATIC
    third_party/lcms2-2.6/include/lcms2.h
    third_party/lcms2-2.6/include/lcms2_plugin.h
    third_party/lcms2-2.6/src/cmscam02.c
    third_party/lcms2-2.6/src/cmscgats.c
    third_party/lcms2-2.6/src/cmscnvrt.c
    third_party/lcms2-2.6/src/cmserr.c
    third_party/lcms2-2.6/src/cmsgamma.c
    third_party/lcms2-2.6/src/cmsgmt.c
    third_party/lcms2-2.6/src/cmshalf.c
    third_party/lcms2-2.6/src/cmsintrp.c
    third_party/lcms2-2.6/src/cmsio0.c
    third_party/lcms2-2.6/src/cmsio1.c
    third_party/lcms2-2.6/src/cmslut.c
    third_party/lcms2-2.6/src/cmsmd5.c
    third_party/lcms2-2.6/src/cmsmtrx.c
    third_party/lcms2-2.6/src/cmsnamed.c
    third_party/lcms2-2.6/src/cmsopt.c
    third_party/lcms2-2.6/src/cmspack.c
    third_party/lcms2-2.6/src/cmspcs.c
    third_party/lcms2-2.6/src/cmsplugin.c
    third_party/lcms2-2.6/src/cmsps2.c
    third_party/lcms2-2.6/src/cmssamp.c
    third_party/lcms2-2.6/src/cmssm.c
    third_party/lcms2-2.6/src/cmstypes.c
    third_party/lcms2-2.6/src/cmsvirt.c
    third_party/lcms2-2.6/src/cmswtpnt.c
    third_party/lcms2-2.6/src/cmsxform.c)

add_library(fx_libopenjpeg STATIC
    third_party/libopenjpeg20/bio.c
    third_party/libopenjpeg20/cio.c
    third_party/libopenjpeg20/dwt.c
    third_party/libopenjpeg20/event.c
    third_party/libopenjpeg20/function_list.c
    third_party/libopenjpeg20/image.c
    third_party/libopenjpeg20/invert.c
    third_party/libopenjpeg20/j2k.c
    third_party/libopenjpeg20/jp2.c
    third_party/libopenjpeg20/mct.c
    third_party/libopenjpeg20/mqc.c
    third_party/libopenjpeg20/openjpeg.c
    third_party/libopenjpeg20/opj_clock.c
    third_party/libopenjpeg20/pi.c
    third_party/libopenjpeg20/raw.c
    third_party/libopenjpeg20/t1.c
    third_party/libopenjpeg20/t2.c
    third_party/libopenjpeg20/tcd.c
    third_party/libopenjpeg20/tgt.c)

add_library(fx_zlib STATIC
    third_party/zlib_v128/adler32.c
    third_party/zlib_v128/compress.c
    third_party/zlib_v128/crc32.c
    third_party/zlib_v128/deflate.c
    third_party/zlib_v128/gzclose.c
    third_party/zlib_v128/gzlib.c
    third_party/zlib_v128/gzread.c
    third_party/zlib_v128/gzwrite.c
    third_party/zlib_v128/infback.c
    third_party/zlib_v128/inffast.c
    third_party/zlib_v128/inflate.c
    third_party/zlib_v128/inftrees.c
    third_party/zlib_v128/trees.c
    third_party/zlib_v128/uncompr.c
    third_party/zlib_v128/zutil.c)

# <(libjpeg_gyp_path):libjpeg
# third_party/third_party.gyp:fx_lcms2
# third_party/third_party.gyp:fx_libopenjpeg
# third_party/third_party.gyp:fx_zlib
add_library(fxcodec STATIC
    core/include/fxcodec/fx_codec.h
    core/include/fxcodec/fx_codec_def.h
    core/include/fxcodec/fx_codec_flate.h
    core/src/fxcodec/codec/codec_int.h
    core/src/fxcodec/codec/fx_codec.cpp
    core/src/fxcodec/codec/fx_codec_fax.cpp
    core/src/fxcodec/codec/fx_codec_flate.cpp
    core/src/fxcodec/codec/fx_codec_icc.cpp
    core/src/fxcodec/codec/fx_codec_jbig.cpp
    core/src/fxcodec/codec/fx_codec_jpeg.cpp
    core/src/fxcodec/codec/fx_codec_jpx_opj.cpp
    core/src/fxcodec/jbig2/JBig2_ArithDecoder.cpp
    core/src/fxcodec/jbig2/JBig2_ArithDecoder.h
    core/src/fxcodec/jbig2/JBig2_ArithIntDecoder.cpp
    core/src/fxcodec/jbig2/JBig2_ArithIntDecoder.h
    core/src/fxcodec/jbig2/JBig2_BitStream.cpp
    core/src/fxcodec/jbig2/JBig2_BitStream.h
    core/src/fxcodec/jbig2/JBig2_Context.cpp
    core/src/fxcodec/jbig2/JBig2_Context.h
    core/src/fxcodec/jbig2/JBig2_Define.h
    core/src/fxcodec/jbig2/JBig2_GrdProc.cpp
    core/src/fxcodec/jbig2/JBig2_GrdProc.h
    core/src/fxcodec/jbig2/JBig2_GrrdProc.cpp
    core/src/fxcodec/jbig2/JBig2_GrrdProc.h
    core/src/fxcodec/jbig2/JBig2_GsidProc.cpp
    core/src/fxcodec/jbig2/JBig2_GsidProc.h
    core/src/fxcodec/jbig2/JBig2_HtrdProc.cpp
    core/src/fxcodec/jbig2/JBig2_HtrdProc.h
    core/src/fxcodec/jbig2/JBig2_HuffmanDecoder.cpp
    core/src/fxcodec/jbig2/JBig2_HuffmanDecoder.h
    core/src/fxcodec/jbig2/JBig2_HuffmanTable.cpp
    core/src/fxcodec/jbig2/JBig2_HuffmanTable.h
    core/src/fxcodec/jbig2/JBig2_HuffmanTable_Standard.h
    core/src/fxcodec/jbig2/JBig2_Image.cpp
    core/src/fxcodec/jbig2/JBig2_Image.h
    core/src/fxcodec/jbig2/JBig2_List.h
    core/src/fxcodec/jbig2/JBig2_Page.h
    core/src/fxcodec/jbig2/JBig2_PatternDict.cpp
    core/src/fxcodec/jbig2/JBig2_PatternDict.h
    core/src/fxcodec/jbig2/JBig2_PddProc.cpp
    core/src/fxcodec/jbig2/JBig2_PddProc.h
    core/src/fxcodec/jbig2/JBig2_SddProc.cpp
    core/src/fxcodec/jbig2/JBig2_SddProc.h
    core/src/fxcodec/jbig2/JBig2_Segment.cpp
    core/src/fxcodec/jbig2/JBig2_Segment.h
    core/src/fxcodec/jbig2/JBig2_SymbolDict.cpp
    core/src/fxcodec/jbig2/JBig2_SymbolDict.h
    core/src/fxcodec/jbig2/JBig2_TrdProc.cpp
    core/src/fxcodec/jbig2/JBig2_TrdProc.h)


add_library(fxcrt STATIC
    core/include/fxcrt/fx_basic.h
    core/include/fxcrt/fx_bidi.h
    core/include/fxcrt/fx_coordinates.h
    core/include/fxcrt/fx_ext.h
    core/include/fxcrt/fx_memory.h
    core/include/fxcrt/fx_safe_types.h
    core/include/fxcrt/fx_stream.h
    core/include/fxcrt/fx_string.h
    core/include/fxcrt/fx_system.h
    core/include/fxcrt/fx_ucd.h
    core/include/fxcrt/fx_xml.h
    core/src/fxcrt/extension.h
    core/src/fxcrt/fxcrt_platforms.cpp
    core/src/fxcrt/fxcrt_platforms.h
    core/src/fxcrt/fxcrt_posix.cpp
    core/src/fxcrt/fxcrt_posix.h
    core/src/fxcrt/fxcrt_windows.cpp
    core/src/fxcrt/fxcrt_windows.h
    core/src/fxcrt/fx_basic_array.cpp
    core/src/fxcrt/fx_basic_bstring.cpp
    core/src/fxcrt/fx_basic_buffer.cpp
    core/src/fxcrt/fx_basic_coords.cpp
    core/src/fxcrt/fx_basic_gcc.cpp
    core/src/fxcrt/fx_basic_list.cpp
    core/src/fxcrt/fx_basic_maps.cpp
    core/src/fxcrt/fx_basic_memmgr.cpp
    core/src/fxcrt/fx_basic_plex.cpp
    core/src/fxcrt/fx_basic_utf.cpp
    core/src/fxcrt/fx_basic_util.cpp
    core/src/fxcrt/fx_basic_wstring.cpp
    core/src/fxcrt/fx_bidi.cpp
    core/src/fxcrt/fx_extension.cpp
    core/src/fxcrt/fx_ucddata.cpp
    core/src/fxcrt/fx_unicode.cpp
    core/src/fxcrt/fx_xml_composer.cpp
    core/src/fxcrt/fx_xml_parser.cpp
    core/src/fxcrt/plex.h
    core/src/fxcrt/xml_int.h)

# third_party/fx_agg
add_library(fxge STATIC
    core/include/fxge/fpf.h
    core/include/fxge/fx_dib.h
    core/include/fxge/fx_font.h
    core/include/fxge/fx_freetype.h
    core/include/fxge/fx_ge.h
    core/include/fxge/fx_ge_apple.h
    core/include/fxge/fx_ge_win32.h
    core/src/fxge/agg/include/fx_agg_driver.h
    core/src/fxge/agg/src/fx_agg_driver.cpp
    core/src/fxge/android/fpf_skiafont.cpp
    core/src/fxge/android/fpf_skiafont.h
    core/src/fxge/android/fpf_skiafontmgr.cpp
    core/src/fxge/android/fpf_skiafontmgr.h
    core/src/fxge/android/fpf_skiamodule.cpp
    core/src/fxge/android/fpf_skiamodule.h
    core/src/fxge/android/fx_android_font.cpp
    core/src/fxge/android/fx_android_font.h
    core/src/fxge/android/fx_android_imp.cpp
    core/src/fxge/android/fx_fpf.h
    core/src/fxge/apple/apple_int.h
    core/src/fxge/apple/fx_apple_platform.cpp
    core/src/fxge/apple/fx_mac_imp.cpp
    core/src/fxge/apple/fx_quartz_device.cpp
    core/src/fxge/dib/dib_int.h
    core/src/fxge/dib/fx_dib_composite.cpp
    core/src/fxge/dib/fx_dib_convert.cpp
    core/src/fxge/dib/fx_dib_engine.cpp
    core/src/fxge/dib/fx_dib_main.cpp
    core/src/fxge/dib/fx_dib_transform.cpp
    core/src/fxge/fontdata/chromefontdata/chromefontdata.h
    core/src/fxge/fontdata/chromefontdata/FoxitDingbats.c
    core/src/fxge/fontdata/chromefontdata/FoxitFixed.c
    core/src/fxge/fontdata/chromefontdata/FoxitFixedBold.c
    core/src/fxge/fontdata/chromefontdata/FoxitFixedBoldItalic.c
    core/src/fxge/fontdata/chromefontdata/FoxitFixedItalic.c
    core/src/fxge/fontdata/chromefontdata/FoxitSans.c
    core/src/fxge/fontdata/chromefontdata/FoxitSansBold.c
    core/src/fxge/fontdata/chromefontdata/FoxitSansBoldItalic.c
    core/src/fxge/fontdata/chromefontdata/FoxitSansItalic.c
    core/src/fxge/fontdata/chromefontdata/FoxitSansMM.c
    core/src/fxge/fontdata/chromefontdata/FoxitSerif.c
    core/src/fxge/fontdata/chromefontdata/FoxitSerifBold.c
    core/src/fxge/fontdata/chromefontdata/FoxitSerifBoldItalic.c
    core/src/fxge/fontdata/chromefontdata/FoxitSerifItalic.c
    core/src/fxge/fontdata/chromefontdata/FoxitSerifMM.c
    core/src/fxge/fontdata/chromefontdata/FoxitSymbol.c
    core/src/fxge/freetype/fx_freetype.c
    core/src/fxge/ge/fx_ge.cpp
    core/src/fxge/ge/fx_ge_device.cpp
    core/src/fxge/ge/fx_ge_font.cpp
    core/src/fxge/ge/fx_ge_fontmap.cpp
    core/src/fxge/ge/fx_ge_linux.cpp
    core/src/fxge/ge/fx_ge_path.cpp
    core/src/fxge/ge/fx_ge_ps.cpp
    core/src/fxge/ge/fx_ge_text.cpp
    core/src/fxge/ge/text_int.h
    third_party/agg23/agg_basics.h
    third_party/agg23/agg_clip_liang_barsky.h
    third_party/agg23/agg_conv_dash.h
    third_party/agg23/agg_conv_stroke.h
    third_party/agg23/agg_curves.cpp
    third_party/agg23/agg_curves.h
    third_party/agg23/agg_path_storage.cpp
    third_party/agg23/agg_path_storage.h
    third_party/agg23/agg_rasterizer_scanline_aa.cpp
    third_party/agg23/agg_rasterizer_scanline_aa.h
    third_party/agg23/agg_renderer_scanline.h
    third_party/agg23/agg_rendering_buffer.h
    third_party/agg23/agg_scanline_u.h
    third_party/agg23/agg_vcgen_dash.cpp
    third_party/agg23/agg_vcgen_stroke.cpp)


add_library(fxedit STATIC
    fpdfsdk/include/fxedit/fx_edit.h
    fpdfsdk/include/fxedit/fxet_edit.h
    fpdfsdk/include/fxedit/fxet_list.h
    fpdfsdk/src/fxedit/fxet_ap.cpp
    fpdfsdk/src/fxedit/fxet_edit.cpp
    fpdfsdk/src/fxedit/fxet_list.cpp
    fpdfsdk/src/fxedit/fxet_module.cpp
    fpdfsdk/src/fxedit/fxet_pageobjs.cpp)


add_library(pdfwindow STATIC
    fpdfsdk/include/pdfwindow/PWL_Button.h
    fpdfsdk/include/pdfwindow/PWL_Caret.h
    fpdfsdk/include/pdfwindow/PWL_ComboBox.h
    fpdfsdk/include/pdfwindow/PWL_Edit.h
    fpdfsdk/include/pdfwindow/PWL_EditCtrl.h
    fpdfsdk/include/pdfwindow/PWL_FontMap.h
    fpdfsdk/include/pdfwindow/PWL_Icon.h
    fpdfsdk/include/pdfwindow/PWL_IconList.h
    fpdfsdk/include/pdfwindow/PWL_Label.h
    fpdfsdk/include/pdfwindow/PWL_ListBox.h
    fpdfsdk/include/pdfwindow/PWL_ListCtrl.h
    fpdfsdk/include/pdfwindow/PWL_Note.h
    fpdfsdk/include/pdfwindow/PWL_ScrollBar.h
    fpdfsdk/include/pdfwindow/PWL_Signature.h
    fpdfsdk/include/pdfwindow/PWL_SpecialButton.h
    fpdfsdk/include/pdfwindow/PWL_Utils.h
    fpdfsdk/include/pdfwindow/PWL_Wnd.h
    fpdfsdk/src/pdfwindow/PWL_Button.cpp
    fpdfsdk/src/pdfwindow/PWL_Caret.cpp
    fpdfsdk/src/pdfwindow/PWL_ComboBox.cpp
    fpdfsdk/src/pdfwindow/PWL_Edit.cpp
    fpdfsdk/src/pdfwindow/PWL_EditCtrl.cpp
    fpdfsdk/src/pdfwindow/PWL_FontMap.cpp
    fpdfsdk/src/pdfwindow/PWL_Icon.cpp
    fpdfsdk/src/pdfwindow/PWL_IconList.cpp
    fpdfsdk/src/pdfwindow/PWL_Label.cpp
    fpdfsdk/src/pdfwindow/PWL_ListBox.cpp
    fpdfsdk/src/pdfwindow/PWL_ListCtrl.cpp
    fpdfsdk/src/pdfwindow/PWL_Note.cpp
    fpdfsdk/src/pdfwindow/PWL_ScrollBar.cpp
    fpdfsdk/src/pdfwindow/PWL_Signature.cpp
    fpdfsdk/src/pdfwindow/PWL_SpecialButton.cpp
    fpdfsdk/src/pdfwindow/PWL_Utils.cpp
    fpdfsdk/src/pdfwindow/PWL_Wnd.cpp)

add_library(javascript STATIC
    fpdfsdk/include/javascript/IJavaScript.h
    fpdfsdk/src/javascript/JS_Runtime_Stub.cpp)


add_library(formfiller STATIC
    fpdfsdk/include/formfiller/FFL_CBA_Fontmap.h
    fpdfsdk/include/formfiller/FFL_CheckBox.h
    fpdfsdk/include/formfiller/FFL_ComboBox.h
    fpdfsdk/include/formfiller/FFL_FormFiller.h
    fpdfsdk/include/formfiller/FFL_IFormFiller.h
    fpdfsdk/include/formfiller/FFL_ListBox.h
    fpdfsdk/include/formfiller/FFL_PushButton.h
    fpdfsdk/include/formfiller/FFL_RadioButton.h
    fpdfsdk/include/formfiller/FFL_TextField.h
    fpdfsdk/src/formfiller/FFL_CBA_Fontmap.cpp
    fpdfsdk/src/formfiller/FFL_CheckBox.cpp
    fpdfsdk/src/formfiller/FFL_ComboBox.cpp
    fpdfsdk/src/formfiller/FFL_FormFiller.cpp
    fpdfsdk/src/formfiller/FFL_IFormFiller.cpp
    fpdfsdk/src/formfiller/FFL_ListBox.cpp
    fpdfsdk/src/formfiller/FFL_PushButton.cpp
    fpdfsdk/src/formfiller/FFL_RadioButton.cpp
    fpdfsdk/src/formfiller/FFL_TextField.cpp)

# file(GLOB_RECURSE freetype_src ${SRC_HOME_PATH}/third_party/freetype/src/*.c)
add_library(fx_freetype STATIC
    third_party/freetype/include/freetype/freetype.h
    third_party/freetype/include/freetype/ftmm.h
    third_party/freetype/include/freetype/ftotval.h
    third_party/freetype/include/freetype/ftoutln.h
    third_party/freetype/include/freetype/internal/ftobjs.h
    third_party/freetype/include/freetype/internal/ftstream.h
    third_party/freetype/include/freetype/internal/tttypes.h
    third_party/freetype/include/freetype/tttables.h
    third_party/freetype/include/ft2build.h
    third_party/freetype/src/base/ftbase.c
    third_party/freetype/src/base/ftbase.h
    third_party/freetype/src/base/ftbitmap.c
    third_party/freetype/src/base/ftglyph.c
    third_party/freetype/src/base/ftinit.c
    third_party/freetype/src/base/ftlcdfil.c
    third_party/freetype/src/base/ftmm.c
    third_party/freetype/src/base/ftsystem.c
    third_party/freetype/src/cff/cff.c
    third_party/freetype/src/cff/cffobjs.h
    third_party/freetype/src/cff/cfftypes.h
    third_party/freetype/src/cid/type1cid.c
    third_party/freetype/src/psaux/psaux.c
    third_party/freetype/src/pshinter/pshinter.c
    third_party/freetype/src/psnames/psmodule.c
    third_party/freetype/src/raster/raster.c
    third_party/freetype/src/sfnt/sfnt.c
    third_party/freetype/src/smooth/smooth.c
    third_party/freetype/src/truetype/truetype.c
    third_party/freetype/src/type1/type1.c)


add_library(pdfium STATIC
    fpdfsdk/include/fsdk_actionhandler.h
    fpdfsdk/include/fsdk_annothandler.h
    fpdfsdk/include/fsdk_baseannot.h
    fpdfsdk/include/fsdk_baseform.h
    fpdfsdk/src/fpdfdoc.cpp
    fpdfsdk/src/fpdfeditimg.cpp
    fpdfsdk/src/fpdfeditpage.cpp
    fpdfsdk/src/fpdfformfill.cpp
    fpdfsdk/src/fpdfppo.cpp
    fpdfsdk/src/fpdfsave.cpp
    fpdfsdk/src/fpdftext.cpp
    fpdfsdk/src/fpdfview.cpp
    fpdfsdk/src/fpdf_dataavail.cpp
    fpdfsdk/src/fpdf_ext.cpp
    fpdfsdk/src/fpdf_flatten.cpp
    fpdfsdk/src/fpdf_progressive.cpp
    fpdfsdk/src/fpdf_searchex.cpp
    fpdfsdk/src/fpdf_sysfontinfo.cpp
    fpdfsdk/src/fpdf_transformpage.cpp
    fpdfsdk/src/fsdk_actionhandler.cpp
    fpdfsdk/src/fsdk_annothandler.cpp
    fpdfsdk/src/fsdk_baseannot.cpp
    fpdfsdk/src/fsdk_baseform.cpp
    fpdfsdk/src/fsdk_mgr.cpp
    fpdfsdk/src/fsdk_rendercontext.cpp
    public/fpdf_dataavail.h
    public/fpdf_doc.h
    public/fpdf_edit.h
    public/fpdf_ext.h
    public/fpdf_flatten.h
    public/fpdf_formfill.h
    public/fpdf_fwlevent.h
    public/fpdf_ppo.h
    public/fpdf_progressive.h
    public/fpdf_save.h
    public/fpdf_searchex.h
    public/fpdf_sysfontinfo.h
    public/fpdf_text.h
    public/fpdf_transformpage.h
    public/fpdfview.h
    third_party/base/logging.h
    third_party/base/macros.h
    third_party/base/numerics/safe_conversions.h
    third_party/base/numerics/safe_conversions_impl.h
    third_party/base/numerics/safe_math.h
    third_party/base/numerics/safe_math_impl.h
    third_party/base/stl_util.h
    third_party/bigint/BigInteger.hh
    third_party/bigint/BigIntegerLibrary.hh
    third_party/bigint/BigIntegerUtils.hh
    third_party/bigint/BigUnsigned.hh
    third_party/bigint/NumberlikeArray.hh
    third_party/bigint/BigUnsignedInABase.hh
    third_party/bigint/BigInteger.cc
    third_party/bigint/BigIntegerUtils.cc
    third_party/bigint/BigUnsigned.cc
    third_party/bigint/BigUnsignedInABase.cc)

add_library(pdfium-lib SHARED  mainJNILib.cpp)

#=====依赖=====

find_library(log-lib log)


target_link_libraries(
    fxcodec
    libjpeg fx_lcms2 fx_libopenjpeg fx_zlib )

target_link_libraries(
    fpdfapi
    fdrm )


target_link_libraries(
    pdfium
    fdrm
    fpdfdoc
    fpdfapi
    fpdftext
    formfiller
    fxcodec
    fxcrt
    fxedit
    fxge
    javascript
    pdfwindow
    fx_freetype)

target_link_libraries(
    pdfium-lib
    pdfium android log jnigraphics)