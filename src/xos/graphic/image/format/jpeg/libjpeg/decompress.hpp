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
///   File: decompress.hpp
///
/// Author: $author$
///   Date: 7/20/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_DECOMPRESS_HPP
#define _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_DECOMPRESS_HPP

#include "xos/graphic/image/format/jpeg/libjpeg/color_space.hpp"
#include "xos/base/created.hpp"
#include "xos/io/logger.hpp"

namespace xos {
namespace graphic {
namespace image {
namespace format {
namespace jpeg {
namespace libjpeg {

typedef jpeg_decompress_struct* decompress_attached_t;
typedef creator decompress_creator;
typedef attachert<decompress_attached_t, int, 0, decompress_creator> decompress_attacher;
typedef attachedt<decompress_attached_t, int, 0, decompress_attacher, base> decompress_attached;
typedef createdt<decompress_attached_t, int, 0, decompress_attacher, decompress_attached> decompress_created;
typedef decompress_attacher decompress_implements;
typedef decompress_created decompress_extends;
///////////////////////////////////////////////////////////////////////
///  Class: decompress
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS decompress
: virtual public decompress_implements, public decompress_extends {
public:
    typedef decompress_implements implements;
    typedef decompress_extends extends;

    typedef typename extends::attached_t attached_t;
    typedef void error_exit_t(j_common_ptr cinfo);
    typedef void output_message_t(j_common_ptr cinfo);

    decompress(attached_t detached = 0, bool is_created = false)
    : extends(detached, is_created) {
    }
    virtual ~decompress() {
    }

    virtual bool create() {
        attached_t detached = 0;
        if ((detached = create_attached())) {
            this->set_is_created();
            return true;
        }
        return false;
    }
    virtual bool destroy() {
        attached_t detached = 0;
        if ((detached = this->detach())) {
            if (!(detached != &jpeg_)) {
                if ((destroy_detached(jpeg_))) {
                    return true;
                }
            } else {
                LOG_ERROR("...unexpected detached != &jpeg_");
            }
        }
        return false;
    }

    virtual attached_t create_attached() {
        attached_t detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached
                 (jpeg_, jerr_, error_exit, output_message))) {
                this->attach(detached);
            }
        }
        return detached;
    }
    virtual attached_t create_detached
    (jpeg_decompress_struct& jpeg, jpeg_error_mgr& jerr,
     error_exit_t error_exit, output_message_t output_message) const {
        jpeg.err = jpeg_std_error(&jerr);
        jerr.error_exit = error_exit;
        jerr.output_message = output_message;
        try {
            jpeg_create_decompress(&jpeg);
            return &jpeg;
        } catch(const error& e) {
            LOG_ERROR("...caught error = " << e.which() << "")
        }
        return 0;
    }
    virtual bool destroy_detached(jpeg_decompress_struct& jpeg) const {
        try {
            jpeg_destroy_decompress(&jpeg);
            return true;
        } catch(const error& e) {
            LOG_ERROR("...caught error = " << e.which() << "")
        }
        return false;
    }

    virtual bool start_read
    (FILE* file, boolean require_image = FALSE, JDIMENSION num_sample_rows = 1) {
        if ((create())) {
            if ((stdio_src(file))) {
                if ((read_header(require_image))) {
                    if ((start_decompress())) {
                        if ((sample_rows_ = alloc_sample_rows(num_sample_rows))) {
                            num_sample_rows_ = num_sample_rows;
                            return true;
                        }
                    }
                }
            }
            destroy();
        }
        return false;
    }
    virtual bool finish_read(FILE* file) {
        bool success = true;
        if (!(destroy())) {
            success = false;
        }
        num_sample_rows_ = 0;
        sample_rows_ = 0;
        return success;
    }

    virtual JSAMPARRAY read_sample_rows(JDIMENSION num_rows = 1) {
        if ((sample_rows_) && (num_sample_rows_) && (num_rows <= num_sample_rows_)) {
            JDIMENSION sample_rows_read = 0;
            if ((sample_rows_read = read_scan_lines(sample_rows_, num_rows))) {
                return sample_rows_;
            }
        }
        return 0;
    }
    virtual JDIMENSION read_scan_lines
    (JSAMPARRAY scan_lines, JDIMENSION max_lines = 1) {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            try {
                JDIMENSION lines = jpeg_read_scanlines(jpeg, scan_lines, max_lines);
                return lines;
            } catch(const error& e) {
                LOG_ERROR("...caught error = " << e.which() << "")
            }
        }
        return 0;
    }
    virtual bool read_header(boolean require_image = FALSE) {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            try {
                int err = jpeg_read_header(jpeg, require_image);
                return true;
            } catch(const error& e) {
                LOG_ERROR("...caught error = " << e.which() << "")
            }
        }
        return false;
    }

    virtual bool start_decompress() {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            try {
                boolean success = jpeg_start_decompress(jpeg);
                return success != FALSE;
            } catch(const error& e) {
                LOG_ERROR("...caught error = " << e.which() << "")
            }
        }
        return false;
    }
    virtual bool finish_decompress() {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            try {
                boolean success = jpeg_finish_decompress(jpeg);
                return success != FALSE;
            } catch(const error& e) {
                LOG_ERROR("...caught error = " << e.which() << "")
            }
        }
        return false;
    }

    virtual bool stdio_src(FILE* file) {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to()) && (file)) {
            try {
                jpeg_stdio_src(jpeg, file);
                return true;
            } catch(const error& e) {
                LOG_ERROR("...caught error = " << e.which() << "")
            }
        }
        return false;
    }

    virtual JSAMPARRAY alloc_sample_rows
    (JDIMENSION num_rows = 1, int pool_id = JPOOL_IMAGE) const {
        JDIMENSION samples_per_row = 0;
        if (0 < (samples_per_row = row_stride())) {
            JSAMPARRAY sample_array = 0;
            if ((sample_array = alloc_sample_array
                 (samples_per_row, num_rows, pool_id))) {
                return sample_array;
            }
        }
        return 0;
    }
    virtual JSAMPARRAY alloc_sample_array
    (JDIMENSION samples_per_row,
     JDIMENSION num_rows = 1, int pool_id = JPOOL_IMAGE) const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            if ((jpeg->mem) && (jpeg->mem->alloc_sarray)) {
                JSAMPARRAY sample_array = 0;
                try {
                    sample_array = (*jpeg->mem->alloc_sarray)
                    ((j_common_ptr)jpeg, pool_id, samples_per_row, num_rows);
                    return sample_array;
                } catch(const error& e) {
                    LOG_ERROR("...caught error = " << e.which() << "")
                }
            }
        }
        return 0;
    }
    virtual bool free_sample_array
    (JSAMPARRAY sample_array, int pool_id = JPOOL_IMAGE) const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            if ((jpeg->mem) && (jpeg->mem->free_pool) && (sample_array)) {
                JSAMPARRAY sample_array = 0;
                try {
                    (*jpeg->mem->free_pool)((j_common_ptr)jpeg, pool_id);
                    return true;
                } catch(const error& e) {
                    LOG_ERROR("...caught error = " << e.which() << "")
                }
            }
        }
        return 0;
    }

    virtual size_t row_stride() const {
        size_t size = (output_width() * output_components());
        return size;
    }

    virtual JDIMENSION output_width() const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            return jpeg->output_width;
        }
        return 0;
    }
    virtual JDIMENSION output_height() const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            return jpeg->output_height;
        }
        return 0;
    }
    virtual JDIMENSION output_scanline() const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            return jpeg->output_scanline;
        }
        return 0;
    }
    virtual JDIMENSION output_components() const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            return jpeg->output_components;
        }
        return 0;
    }
    virtual JDIMENSION out_color_components() const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            return jpeg->out_color_components;
        }
        return 0;
    }
    virtual JDIMENSION actual_number_of_colors() const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            return jpeg->actual_number_of_colors;
        }
        return 0;
    }
    virtual J_COLOR_SPACE out_color_space() const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            return jpeg->out_color_space;
        }
        return JCS_UNKNOWN;
    }
    virtual JSAMPARRAY colormap() const {
        attached_t jpeg = 0;
        if ((jpeg = this->attached_to())) {
            return jpeg->colormap;
        }
        return 0;
    }


    static void error_exit(j_common_ptr cinfo) {
        LOG_ERROR("throwing error(error_failed)...");
        throw error(error_failed);
    }
    static void output_message(j_common_ptr cinfo) {
    }

protected:
    jpeg_error_mgr jerr_;
    jpeg_decompress_struct jpeg_;
    JSAMPARRAY sample_rows_;
    JDIMENSION num_sample_rows_;
};

} /// namespace libjpeg
} /// namespace jpeg
} /// namespace format
} /// namespace image
} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_IMAGE_FORMAT_JPEG_LIBJPEG_DECOMPRESS_HPP 
