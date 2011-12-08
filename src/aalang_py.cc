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
 *
 */

#include "aalang_py.hh"
#include "helper.hh"

void aalang_py::set_starter(std::string* st)
{
  s+=*st;
}


void aalang_py::set_name(std::string* name)
{
    s+="    action"+acnt+"name = \""+*name+"\"\n"
      +"    action"+acnt+"type = \"input\"\n\n";
}

void aalang_py::set_namestr(std::string* _name)
{ 
  name=_name;
  s+="class _gen_"+*name+"(AALModel):\n";
}

void aalang_py::set_variables(std::string* var)
{
}

void aalang_py::set_istate(std::string* ist)
{
}

void aalang_py::set_guard(std::string* gua)
{
  s+="    def action"+acnt+"guard():"+*gua+"\n";
}

void aalang_py::set_body(std::string* bod)
{
  s+="    def action"+acnt+"body():"+*bod+"\n";
}

void aalang_py::set_adapter(std::string* ada)
{
  s+="    def action"+acnt+"adapter():"+*ada+"\n";
}

void aalang_py::next_action()
{
  action_cnt++;
  acnt=to_string(action_cnt);
}

std::string aalang_py::stringify()
{
  return s;
}
