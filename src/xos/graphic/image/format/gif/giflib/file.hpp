///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: file.hpp
///
/// Author: $author$
///   Date: 7/22/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_HPP

#include "xos/graphic/image/format/gif/giflib/giflib.hpp"
#include "xos/base/opened.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace gif {
namespace giflib {

typedef GifFileType* file_attached_t;
typedef xos::opener file_opener;
typedef xos::attachert<file_attached_t, int, 0, file_opener> file_attacher;
typedef xos::attachedt<file_attached_t, int, 0, file_attacher, base> file_attached;
typedef xos::openedt<file_attached_t, int, 0, file_attacher, file_attached> file_extend;
typedef file_attacher file_implements;
typedef file_extend file_extends;
///////////////////////////////////////////////////////////////////////
///  Class: file
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS file: virtual public file_implements, public file_extends {
public:
    typedef file_implements implements;
    typedef file_extends extends;

    typedef typename implements::attached_t attached_t;
    typedef typename implements::unattached_t unattached_t;
    static const unattached_t unattached = implements::unattached;

    file(attached_t detached = 0, bool is_open = false): extends(detached, is_open) {
    }
    virtual ~file() {
        if (!(this->closed())) {
            LOG_ERROR("...failed on this->closed() throw (open_exception(close_failed))...");
            throw (open_exception(close_failed));
        }
    }

    virtual bool open(const char* file) {
        attached_t detached = (attached_t)(unattached);
        if ((attached_t)(unattached) != (detached = this->open_attached(file))) {
            this->set_is_open();
            return true;
        }
        return false;
    }
    virtual attached_t open_attached(const char* file) {
        attached_t detached = (attached_t)(unattached);
        if ((this->closed())) {
            if ((attached_t)(unattached) != (detached = open_detached(file))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t open_detached(const char* file) const {
        attached_t detached = 0;
        if ((file) && (file[0])) {
            LOG_DEBUG("DGifOpenFileName(file = \"" << file << "\")...");
            if (!(detached = DGifOpenFileName(file))) {
                int err = GifLastError();
                LOG_ERROR("...failed err = " << err << " on DGifOpenFileName(file = \"" << file << "\")");
            } else {
                LOG_DEBUG("..." << pointer_to_string(detached) << " = DGifOpenFileName(file = \"" << file << "\")");
            }
        }
        return detached;
    }
    virtual bool close_detached(attached_t detached) const {
        if ((detached)) {
            int err = 0;
            LOG_DEBUG("DGifCloseFile(detached = " << pointer_to_string(detached) << ")...");
            if (GIF_OK != (err = DGifCloseFile(detached))) {
                LOG_ERROR("...failed " << err << " on DGifCloseFile(detached = " << pointer_to_string(detached) << ")...");
            } else {
                LOG_DEBUG("...DGifCloseFile(detached = " << pointer_to_string(detached) << ")");
                return true;
            }
        }
        return false;
    }

    virtual GifImageDesc* GetImageDesc() {
        GifFileType* detached = 0;
        if ((detached = this->attached_to())) {
            int err = GIF_OK;
            LOG_DEBUG("DGifGetImageDesc(attached = " << pointer_to_string(detached) << ")...");
            if (GIF_OK == (err = DGifGetImageDesc(detached))) {
                return &detached->Image;
            } else {
                LOG_ERROR("...failed " << err << " = DGifGetImageDesc(attached = " << pointer_to_string(detached) << ")");
            }
        }
        return 0;
    }
    virtual ssize_t GetLine(GifPixelType* line, size_t size) {
        GifFileType* detached = 0;
        if ((detached = this->attached_to())) {
            if ((line) && (size)) {
                int err = GIF_OK;
                LOG_DEBUG("DGifGetLine(detached = " << pointer_to_string(detached) << ", line = " << pointer_to_string(line) << ", size = " << size << ")...");
                if (GIF_OK == (err = DGifGetLine(detached, line, size))) {
                    return size;
                } else {
                    LOG_DEBUG("...failed " << err << " = DGifGetLine(detached = " << pointer_to_string(detached) << ", line = " << pointer_to_string(line) << ", size = " << size << ")");
                }
            }
        }
        return 0;
    }
    virtual GifByteType* GetExtension(int& extCode) {
        GifFileType* detached = 0;
        if ((detached = this->attached_to())) {
            int err = GIF_OK;
            GifByteType* extBytes = 0;
            LOG_DEBUG("DGifGetExtension(detached = " << pointer_to_string(detached) << ", &extCode, &extBytes)...");
            if (GIF_OK == (err = DGifGetExtension(detached, &extCode, &extBytes))) {
                LOG_DEBUG("...DGifGetExtension(detached = " << pointer_to_string(detached) << ", &extCode = " << extCode << ", &extBytes = " << pointer_to_string(extBytes) << ")");
                return extBytes;
            } else {
                LOG_ERROR("...failed " << err << " = DGifGetExtension(detached = " << pointer_to_string(detached) << ", &extCode, &extBytes)...");
            }
        }
        return 0;
    }
    virtual GifByteType* GetExtensionNext() {
        GifFileType* detached = 0;
        if ((detached = this->attached_to())) {
            int err = GIF_OK;
            GifByteType* extBytes = 0;
            LOG_DEBUG("DGifGetExtensionNext(detached = " << pointer_to_string(detached) << ", &extBytes)...");
            if (GIF_OK == (err = DGifGetExtensionNext(detached, &extBytes))) {
                LOG_DEBUG("...DGifGetExtensionNext(detached = " << pointer_to_string(detached) << ", &extBytes = " << pointer_to_string(extBytes) << ")");
                return extBytes;
            } else {
                LOG_ERROR("...failed " << err << " = DGifGetExtensionNext(detached = " << pointer_to_string(detached) << ", &extBytes)...");
            }
        }
        return 0;
    }
    virtual GifRecordType GetRecordType() {
        GifFileType* detached = 0;
        if ((detached = this->attached_to())) {
            int err = GIF_OK;
            GifRecordType type = UNDEFINED_RECORD_TYPE;
            LOG_DEBUG("DGifGetRecordType(detached = " << pointer_to_string(detached) << ", &type)...");
            if (GIF_OK == (err = DGifGetRecordType(detached, &type))) {
                LOG_DEBUG("...DGifGetRecordType(detached = " << pointer_to_string(detached) << ", &type = " << type << ")...");
                return type;
            } else {
                LOG_ERROR("...failed " << err << " = DGifGetRecordType(detached = " << pointer_to_string(detached) << ", &type)");
            }
        }
        return UNDEFINED_RECORD_TYPE;
    }
    
    virtual TSIZE ColorResolution() const {
        GifFileType* detached = 0;
        if ((detached = this->attached_to())) {
            return detached->SColorResolution;
        }
        return 0;
    }
    virtual GifPixelType BackGroundColor() const {
        GifFileType* detached = 0;
        if ((detached = this->attached_to())) {
            return detached->SBackGroundColor;
        }
        return 0;
    }
    virtual ColorMapObject* ColorMap() const {
        GifFileType* detached = 0;
        if ((detached = this->attached_to())) {
            return detached->SColorMap;
        }
        return 0;
    }
};

} /// namespace giflib
} /// namespace gif
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_GIF_GIFLIB_FILE_HPP 
