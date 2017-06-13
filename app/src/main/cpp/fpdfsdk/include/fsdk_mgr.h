// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FPDFSDK_INCLUDE_FSDK_MGR_H_
#define FPDFSDK_INCLUDE_FSDK_MGR_H_

#include <map>
#include <memory>

#include "core/include/fpdftext/fpdf_text.h"
#include "fsdk_actionhandler.h"
#include "fsdk_common.h"
#include "fsdk_define.h"
#include "fx_systemhandler.h"
#include "public/fpdf_formfill.h"
#include "public/fpdf_fwlevent.h"  // cross platform keycode and events define.

class CFFL_IFormFiller;
class CPDFSDK_ActionHandler;
class CPDFSDK_Annot;
class CPDFSDK_Document;
class CPDFSDK_InterForm;
class CPDFSDK_PageView;
class CPDFSDK_Widget;
class IFX_SystemHandler;

class CPDFDoc_Environment final {
 public:

  void FFI_Invalidate(FPDF_PAGE page,
                      double left,
                      double top,
                      double right,
                      double bottom) {
    if (m_pInfo && m_pInfo->FFI_Invalidate)
      m_pInfo->FFI_Invalidate(m_pInfo, page, left, top, right, bottom);
  }

  void FFI_OutputSelectedRect(FPDF_PAGE page,
                              double left,
                              double top,
                              double right,
                              double bottom) {
    if (m_pInfo && m_pInfo->FFI_OutputSelectedRect)
      m_pInfo->FFI_OutputSelectedRect(m_pInfo, page, left, top, right, bottom);
  }

  void FFI_SetCursor(int nCursorType) {
    if (m_pInfo && m_pInfo->FFI_SetCursor)
      m_pInfo->FFI_SetCursor(m_pInfo, nCursorType);
  }

  int FFI_SetTimer(int uElapse, TimerCallback lpTimerFunc) {
    if (m_pInfo && m_pInfo->FFI_SetTimer)
      return m_pInfo->FFI_SetTimer(m_pInfo, uElapse, lpTimerFunc);
    return -1;
  }

  void FFI_KillTimer(int nTimerID) {
    if (m_pInfo && m_pInfo->FFI_KillTimer)
      m_pInfo->FFI_KillTimer(m_pInfo, nTimerID);
  }

  FX_SYSTEMTIME FFI_GetLocalTime() const {
    FX_SYSTEMTIME fxtime;
    if (m_pInfo && m_pInfo->FFI_GetLocalTime) {
      FPDF_SYSTEMTIME systime = m_pInfo->FFI_GetLocalTime(m_pInfo);
      fxtime.wDay = systime.wDay;
      fxtime.wDayOfWeek = systime.wDayOfWeek;
      fxtime.wHour = systime.wHour;
      fxtime.wMilliseconds = systime.wMilliseconds;
      fxtime.wMinute = systime.wMinute;
      fxtime.wMonth = systime.wMonth;
      fxtime.wSecond = systime.wSecond;
      fxtime.wYear = systime.wYear;
    }
    return fxtime;
  }

  void FFI_OnChange() {
    if (m_pInfo && m_pInfo->FFI_OnChange)
      m_pInfo->FFI_OnChange(m_pInfo);
  }

  FX_BOOL FFI_IsSHIFTKeyDown(FX_DWORD nFlag) const {
    return (nFlag & FWL_EVENTFLAG_ShiftKey) != 0;
  }

  FX_BOOL FFI_IsCTRLKeyDown(FX_DWORD nFlag) const {
    return (nFlag & FWL_EVENTFLAG_ControlKey) != 0;
  }

  FX_BOOL FFI_IsALTKeyDown(FX_DWORD nFlag) const {
    return (nFlag & FWL_EVENTFLAG_AltKey) != 0;
  }

  FX_BOOL FFI_IsINSERTKeyDown(FX_DWORD nFlag) const { return FALSE; }


  FPDF_PAGE FFI_GetPage(FPDF_DOCUMENT document, int nPageIndex) {
    if (m_pInfo && m_pInfo->FFI_GetPage)
      return m_pInfo->FFI_GetPage(m_pInfo, document, nPageIndex);
    return NULL;
  }

  FPDF_PAGE FFI_GetCurrentPage(FPDF_DOCUMENT document) {
    if (m_pInfo && m_pInfo->FFI_GetCurrentPage)
      return m_pInfo->FFI_GetCurrentPage(m_pInfo, document);
    return NULL;
  }

  int FFI_GetRotation(FPDF_PAGE page) {
    if (m_pInfo && m_pInfo->FFI_GetRotation)
      return m_pInfo->FFI_GetRotation(m_pInfo, page);
    return 0;
  }

  void FFI_ExecuteNamedAction(const FX_CHAR* namedAction) {
    if (m_pInfo && m_pInfo->FFI_ExecuteNamedAction)
      m_pInfo->FFI_ExecuteNamedAction(m_pInfo, namedAction);
  }

  void FFI_OnSetFieldInputFocus(void* field,
                                FPDF_WIDESTRING focusText,
                                FPDF_DWORD nTextLen,
                                FX_BOOL bFocus) {
    if (m_pInfo && m_pInfo->FFI_SetTextFieldFocus)
      m_pInfo->FFI_SetTextFieldFocus(m_pInfo, focusText, nTextLen, bFocus);
  }

  void FFI_DoURIAction(const FX_CHAR* bsURI) {
    if (m_pInfo && m_pInfo->FFI_DoURIAction)
      m_pInfo->FFI_DoURIAction(m_pInfo, bsURI);
  }

  void FFI_DoGoToAction(int nPageIndex,
                        int zoomMode,
                        float* fPosArray,
                        int sizeOfArray) {
    if (m_pInfo && m_pInfo->FFI_DoGoToAction)
      m_pInfo->FFI_DoGoToAction(m_pInfo, nPageIndex, zoomMode, fPosArray,
                                sizeOfArray);
  }


  FX_BOOL IsJSInitiated() const { return m_pInfo && m_pInfo->m_pJsPlatform; }
  void SetSDKDocument(CPDFSDK_Document* pFXDoc) { m_pSDKDoc = pFXDoc; }
  CPDFSDK_Document* GetSDKDocument() const { return m_pSDKDoc; }
  UnderlyingDocumentType* GetUnderlyingDocument() const {
    return m_pUnderlyingDoc;
  }
  CFX_ByteString GetAppName() const { return ""; }
  IFX_SystemHandler* GetSysHandler() const { return m_pSysHandler.get(); }
  FPDF_FORMFILLINFO* GetFormFillInfo() const { return m_pInfo; }


 private:
  std::unique_ptr<CPDFSDK_ActionHandler> m_pActionHandler;
  FPDF_FORMFILLINFO* const m_pInfo;
  CPDFSDK_Document* m_pSDKDoc;
  UnderlyingDocumentType* const m_pUnderlyingDoc;
  std::unique_ptr<CFFL_IFormFiller> m_pIFormFiller;
  std::unique_ptr<IFX_SystemHandler> m_pSysHandler;
};

class CPDFSDK_Document {
 public:

  // Gets the document object for the next layer down; for master this is
  // a CPDF_Document, but for XFA it is a CPDFXFA_Document.
  UnderlyingDocumentType* GetUnderlyingDocument() const {
  return GetPDFDocument();

  }

  // Gets the CPDF_Document, either directly in master, or from the
  // CPDFXFA_Document for XFA.
  CPDF_Document* GetPDFDocument() const {
  return m_pDoc;
  }



  int GetPageCount() { return m_pDoc->GetPageCount(); }

  FX_BOOL GetChangeMark() { return m_bChangeMask; }
  void SetChangeMark() { m_bChangeMask = TRUE; }
  void ClearChangeMark() { m_bChangeMask = FALSE; }

  CPDFDoc_Environment* GetEnv() { return m_pEnv; }


 private:
  std::map<UnderlyingPageType*, CPDFSDK_PageView*> m_pageMap;
  UnderlyingDocumentType* m_pDoc;
  std::unique_ptr<CPDFSDK_InterForm> m_pInterForm;
  CPDFSDK_Annot* m_pFocusAnnot;
  CPDFDoc_Environment* m_pEnv;
  std::unique_ptr<CPDF_OCContext> m_pOccontent;
  FX_BOOL m_bChangeMask;
  FX_BOOL m_bBeingDestroyed;
};
class CPDFSDK_PageView final {
 public:


  CPDF_Page* GetPDFPage() { return m_page; }


  CPDFSDK_Document* GetSDKDocument() { return m_pSDKDoc; }

  void GetCurrentMatrix(CFX_Matrix& matrix) { matrix = m_curMatrix; }

  const std::vector<CPDFSDK_Annot*>& GetAnnotList() const {
    return m_fxAnnotArray;
  }


  void SetValid(FX_BOOL bValid) { m_bValid = bValid; }
  FX_BOOL IsValid() { return m_bValid; }
  void SetLock(FX_BOOL bLocked) { m_bLocked = bLocked; }
  FX_BOOL IsLocked() { return m_bLocked; }

 private:

  CFX_Matrix m_curMatrix;
  UnderlyingPageType* m_page;
  std::vector<CPDFSDK_Annot*> m_fxAnnotArray;
  CPDFSDK_Document* m_pSDKDoc;
  CPDFSDK_Widget* m_CaptureWidget;
  FX_BOOL m_bTakeOverPage;
  FX_BOOL m_bValid;
  FX_BOOL m_bLocked;
};

#endif  // FPDFSDK_INCLUDE_FSDK_MGR_H_
