#ifndef _WX_GTK_GDKCANVAS_H
#define _WX_GTK_GDKCANVAS_H

#define GL_GLEXT_PROTOTYPES 1
#include <GL/gl.h>
#include <gdk/gdk.h>

#include <X11/Xutil.h>

// ----------------------------------------------------------------------------
// wxGLContext
// ----------------------------------------------------------------------------

class WXDLLIMPEXP_GL wxGLContext : public wxGLContextBase
{
public:
    wxGLContext(wxGLCanvas *win,
                const wxGLContext *other = NULL,
                const wxGLContextAttrs *ctxAttrs = NULL);
    virtual ~wxGLContext();

    virtual bool SetCurrent(const wxGLCanvas& win) const wxOVERRIDE;

private:
    mutable GdkGLContext* m_glContext;

    wxDECLARE_CLASS(wxGLContext);
};

// ----------------------------------------------------------------------------
// wxGLCanvasGdk
// ----------------------------------------------------------------------------

class WXDLLIMPEXP_GL wxGLCanvasGdk : public wxGLCanvasBase
{
public:
    // initialization and dtor
    // -----------------------

    // default ctor doesn't do anything, InitVisual() must be called
    wxGLCanvasGdk();

    bool InitVisual(const wxGLAttributes& dispAttrs, GdkWindow* window);

    virtual ~wxGLCanvasGdk();
    XVisualInfo *GetXVisualInfo() const { return NULL; }


    // implement wxGLCanvasBase methods
    // --------------------------------

    virtual bool SwapBuffers() wxOVERRIDE;
    gboolean needs_resize;
    void attach_buffers();
private:
    void allocate_buffers();
    void ensure_buffers();
    gboolean have_buffers;
    guint frame_buffer;
    guint render_buffer;
    guint depth_stencil_buffer;

    gboolean needs_render;
    
    int old_w;
    int old_h;
};

#endif 
