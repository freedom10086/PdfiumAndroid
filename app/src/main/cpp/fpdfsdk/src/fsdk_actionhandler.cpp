// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "fpdfsdk/include/fsdk_actionhandler.h"
#include "fpdfsdk/include/fsdk_define.h"
#include "fpdfsdk/include/fsdk_mgr.h"


FX_BOOL CPDFSDK_ActionHandler::DoAction_DocOpen(const CPDF_Action &action,
                                                CPDFSDK_Document *pDocument) {
    CFX_PtrList list;
    return ExecuteDocumentOpenAction(action, pDocument, list);
}


FX_BOOL CPDFSDK_ActionHandler::DoAction_Page(
        const CPDF_Action &action,
        enum CPDF_AAction::AActionType eType,
        CPDFSDK_Document *pDocument) {
    CFX_PtrList list;
    return ExecuteDocumentPageAction(action, eType, pDocument, list);
}

FX_BOOL CPDFSDK_ActionHandler::DoAction_Document(
        const CPDF_Action &action,
        enum CPDF_AAction::AActionType eType,
        CPDFSDK_Document *pDocument) {
    CFX_PtrList list;
    return ExecuteDocumentPageAction(action, eType, pDocument, list);
}

FX_BOOL CPDFSDK_ActionHandler::DoAction_BookMark(CPDF_Bookmark *pBookMark,
                                                 const CPDF_Action &action,
                                                 CPDF_AAction::AActionType type,
                                                 CPDFSDK_Document *pDocument) {
    CFX_PtrList list;
    return ExecuteBookMark(action, pDocument, pBookMark, list);
}


FX_BOOL CPDFSDK_ActionHandler::ExecuteDocumentOpenAction(
        const CPDF_Action &action,
        CPDFSDK_Document *pDocument,
        CFX_PtrList &list) {
    CPDF_Dictionary *pDict = action.GetDict();
    if (list.Find(pDict))
        return FALSE;

    list.AddTail(pDict);

    DoAction_NoJs(action, pDocument);
    for (int32_t i = 0, sz = action.GetSubActionsCount(); i < sz; i++) {
        CPDF_Action subaction = action.GetSubAction(i);
        if (!ExecuteDocumentOpenAction(subaction, pDocument, list))
            return FALSE;
    }

    return TRUE;
}


FX_BOOL CPDFSDK_ActionHandler::ExecuteDocumentPageAction(
        const CPDF_Action &action,
        CPDF_AAction::AActionType type,
        CPDFSDK_Document *pDocument,
        CFX_PtrList &list) {
    CPDF_Dictionary *pDict = action.GetDict();
    if (list.Find(pDict))
        return FALSE;

    list.AddTail(pDict);
    DoAction_NoJs(action, pDocument);
    if (!IsValidDocView(pDocument))
        return FALSE;

    for (int32_t i = 0, sz = action.GetSubActionsCount(); i < sz; i++) {
        CPDF_Action subaction = action.GetSubAction(i);
        if (!ExecuteDocumentPageAction(subaction, type, pDocument, list))
            return FALSE;
    }

    return TRUE;
}


FX_BOOL CPDFSDK_ActionHandler::ExecuteBookMark(const CPDF_Action &action,
                                               CPDFSDK_Document *pDocument,
                                               CPDF_Bookmark *pBookmark,
                                               CFX_PtrList &list) {
    CPDF_Dictionary *pDict = action.GetDict();
    if (list.Find(pDict))
        return FALSE;
    list.AddTail(pDict);
    DoAction_NoJs(action, pDocument);

    for (int32_t i = 0, sz = action.GetSubActionsCount(); i < sz; i++) {
        CPDF_Action subaction = action.GetSubAction(i);
        if (!ExecuteBookMark(subaction, pDocument, pBookmark, list))
            return FALSE;
    }

    return TRUE;
}

void CPDFSDK_ActionHandler::DoAction_NoJs(const CPDF_Action &action,
                                          CPDFSDK_Document *pDocument) {
    ASSERT(pDocument);

    switch (action.GetType()) {
        case CPDF_Action::GoTo:
            DoAction_GoTo(pDocument, action);
            break;
        case CPDF_Action::GoToR:
            DoAction_GoToR(pDocument, action);
            break;
        case CPDF_Action::GoToE:
            break;
        case CPDF_Action::Launch:
            DoAction_Launch(pDocument, action);
            break;
        case CPDF_Action::Thread:
            break;
        case CPDF_Action::URI:
            DoAction_URI(pDocument, action);
            break;
        case CPDF_Action::Sound:
            break;
        case CPDF_Action::Movie:
            break;
        case CPDF_Action::Named:
            DoAction_Named(pDocument, action);
            break;
        case CPDF_Action::JavaScript:
            ASSERT(FALSE);
            break;
        case CPDF_Action::SetOCGState:
            DoAction_SetOCGState(pDocument, action);
            break;
        case CPDF_Action::Rendition:
            break;
        case CPDF_Action::Trans:
            break;
        case CPDF_Action::GoTo3DView:
            break;
        default:
            break;
    }
}

FX_BOOL CPDFSDK_ActionHandler::IsValidDocView(CPDFSDK_Document *pDocument) {
    ASSERT(pDocument);
    return TRUE;
}

void CPDFSDK_ActionHandler::DoAction_GoTo(CPDFSDK_Document *pDocument,
                                          const CPDF_Action &action) {
    ASSERT(action);

    CPDF_Document *pPDFDocument = pDocument->GetPDFDocument();
    ASSERT(pPDFDocument);

    CPDF_Dest MyDest = action.GetDest(pPDFDocument);
    int nPageIndex = MyDest.GetPageIndex(pPDFDocument);
    int nFitType = MyDest.GetZoomMode();
    const CPDF_Array *pMyArray = ToArray(MyDest.GetObject());
    float *pPosAry = nullptr;
    int sizeOfAry = 0;
    if (pMyArray) {
        pPosAry = new float[pMyArray->GetCount()];
        int j = 0;
        for (int i = 2; i < (int) pMyArray->GetCount(); i++) {
            pPosAry[j++] = pMyArray->GetFloat(i);
        }
        sizeOfAry = j;
    }

    CPDFDoc_Environment *pApp = pDocument->GetEnv();
    pApp->FFI_DoGoToAction(nPageIndex, nFitType, pPosAry, sizeOfAry);
    delete[] pPosAry;
}

void CPDFSDK_ActionHandler::DoAction_GoToR(CPDFSDK_Document *pDocument,
                                           const CPDF_Action &action) {}

void CPDFSDK_ActionHandler::DoAction_Launch(CPDFSDK_Document *pDocument,
                                            const CPDF_Action &action) {}

void CPDFSDK_ActionHandler::DoAction_URI(CPDFSDK_Document *pDocument,
                                         const CPDF_Action &action) {
    ASSERT(action);

    CPDFDoc_Environment *pApp = pDocument->GetEnv();
    CFX_ByteString sURI = action.GetURI(pDocument->GetPDFDocument());
    pApp->FFI_DoURIAction(sURI.c_str());
}

void CPDFSDK_ActionHandler::DoAction_Named(CPDFSDK_Document *pDocument,
                                           const CPDF_Action &action) {
    ASSERT(action);

    CFX_ByteString csName = action.GetNamedAction();
    pDocument->GetEnv()->FFI_ExecuteNamedAction(csName);
}

void CPDFSDK_ActionHandler::DoAction_SetOCGState(CPDFSDK_Document *pDocument,
                                                 const CPDF_Action &action) {}
