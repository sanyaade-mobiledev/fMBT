/*
 * fMBT, free Model Based Testing tool
 * Copyright (c) 2011, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#ifndef __of_csv_hh__
#define __of_csv_hh__

#include "of.hh"

/* rfc4180 */

class OutputFormat_Csv: public OutputFormat {
public:
  OutputFormat_Csv(std::string params): OutputFormat(params) {}
  virtual ~OutputFormat_Csv() {}
  
  virtual std::string header() {
    std::string ret("\"UC\",\"verdict\"");

    for(unsigned i=0;i<covnames.size();i++) {
      ret=ret+","+csv_escape(covnames[i]);
    }
    ret=ret+CRLF;
    return ret;
  }
  virtual std::string footer() {
    return "";
  }
  virtual std::string format_covs();
  virtual std::string report() { return "";}
private:
  std::string csv_escape(std::string&);
  static std::string CRLF;
};

#endif
