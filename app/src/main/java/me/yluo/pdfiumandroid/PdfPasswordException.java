package me.yluo.pdfiumandroid;

import java.io.IOException;

public class PdfPasswordException extends IOException {
    public PdfPasswordException() {
        super();
    }

    public PdfPasswordException(String detailMessage) {
        super(detailMessage);
    }
}
