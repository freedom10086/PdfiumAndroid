// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef FPDFSDK_INCLUDE_FSDK_ACTIONHANDLER_H_
#define FPDFSDK_INCLUDE_FSDK_ACTIONHANDLER_H_

#include <memory>

#include "core/include/fpdfdoc/fpdf_doc.h"
#include "core/include/fxcrt/fx_string.h"

class CFX_PtrList;
class CPDFSDK_Annot;
class CPDFSDK_Document;
class CPDF_Bookmark;
class CPDF_Dictionary;


class CPDFSDK_ActionHandler {
 public:

  FX_BOOL DoAction_DocOpen(const CPDF_Action& action,
                           CPDFSDK_Document* pDocument);

  FX_BOOL DoAction_Page(const CPDF_Action& action,
                        enum CPDF_AAction::AActionType eType,
                        CPDFSDK_Document* pDocument);
  FX_BOOL DoAction_Document(const CPDF_Action& action,
                            enum CPDF_AAction::AActionType eType,
                            CPDFSDK_Document* pDocument);
  FX_BOOL DoAction_BookMark(CPDF_Bookmark* pBookMark,
                            const CPDF_Action& action,
                            CPDF_AAction::AActionType type,
                            CPDFSDK_Document* pDocument);


 private:
  FX_BOOL ExecuteDocumentOpenAction(const CPDF_Action& action,
                                    CPDFSDK_Document* pDocument,
                                    CFX_PtrList& list);
  FX_BOOL ExecuteDocumentPageAction(const CPDF_Action& action,
                                    CPDF_AAction::AActionType type,
                                    CPDFSDK_Document* pDocument,
                                    CFX_PtrList& list);


  FX_BOOL ExecuteBookMark(const CPDF_Action& action,
                          CPDFSDK_Document* pDocument,
                          CPDF_Bookmark* pBookmark,
                          CFX_PtrList& list);


  void DoAction_NoJs(const CPDF_Action& action, CPDFSDK_Document* pDocument);


  FX_BOOL IsValidDocView(CPDFSDK_Document* pDocument);

  void DoAction_GoTo(CPDFSDK_Document* pDocument, const CPDF_Action& action);
  void DoAction_GoToR(CPDFSDK_Document* pDocument, const CPDF_Action& action);
  void DoAction_Launch(CPDFSDK_Document* pDocument, const CPDF_Action& action);
  void DoAction_URI(CPDFSDK_Document* pDocument, const CPDF_Action& action);
  void DoAction_Named(CPDFSDK_Document* pDocument, const CPDF_Action& action);
  void DoAction_SetOCGState(CPDFSDK_Document* pDocument, const CPDF_Action& action);
};

#endif  // FPDFSDK_INCLUDE_FSDK_ACTIONHANDLER_H_
