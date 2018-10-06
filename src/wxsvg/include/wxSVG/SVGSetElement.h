//////////////////////////////////////////////////////////////////////////////
// Name:        SVGSetElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_SET_ELEMENT_H
#define WX_SVG_SET_ELEMENT_H

#include "SVGAnimationElement.h"
#include "String_wxsvg.h"
#include "Element.h"

class wxSVGSetElement:
  public wxSVGAnimationElement
{
  public:
    wxSVGSetElement(wxString tagName = wxT("set")):
      wxSVGAnimationElement(tagName) {}
    virtual ~wxSVGSetElement() {}
    wxSvgXmlNode* CloneNode(bool deep = true) { return new wxSVGSetElement(*this); }
    bool HasAttribute(const wxString& name) const;
    wxString GetAttribute(const wxString& name) const;
    bool SetAttribute(const wxString& name, const wxString& value);
    wxSvgXmlAttrHash GetAttributes() const;
    virtual wxSVGDTD GetDtd() const { return wxSVG_SET_ELEMENT; }
};

#endif // WX_SVG_SET_ELEMENT_H
