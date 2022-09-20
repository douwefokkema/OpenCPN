/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:
 *
 * Author:   David Register, Alec Leamas
 *
 ***************************************************************************
 *   Copyright (C) 2022 by David Register, Alec Leamas                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 **************************************************************************/

#ifndef _COMM_DECODER_H
#define _COMM_DECODER_H

#include <memory>
#include <string>

#include <wx/jsonval.h>
#include <wx/string.h>

#include "comm_appmsg.h"
#include "nmea0183.h"
#include "N2KParser.h"



typedef struct{
  double gLat;
  double gLon;
  double gSog;
  double gCog;
  double gHdt;
  double gHdm;
  double gVar;
  int n_satellites;
  int SID;
} NavData;

class CommDecoder {
public:
  CommDecoder(){};
  ~CommDecoder(){};

  // NMEA0183 decoding, by sentence.
  bool DecodeRMC(std::string s, NavData& temp_data);
  bool DecodeHDM(std::string s, NavData& temp_data);
  bool DecodeHDT(std::string s, NavData& temp_data);
  bool DecodeHDG(std::string s, NavData& temp_data);
  bool DecodeVTG(std::string s, NavData& temp_data);
  bool DecodeGSV(std::string s, NavData& temp_data);
  bool DecodeGGA(std::string s, NavData& temp_data);
  bool DecodeGLL(std::string s, NavData& temp_data);

  bool ParsePosition(const LATLONG& Position, double& lat, double& lon);

  NMEA0183 m_NMEA0183;  // Used to parse messages from NMEA threads

  // NMEA2000 decoding, by PGN
  bool DecodePGN129025(std::vector<unsigned char> v,  NavData& temp_data);
  bool DecodePGN129026(std::vector<unsigned char> v,  NavData& temp_data);
  bool DecodePGN129029(std::vector<unsigned char> v,  NavData& temp_data);
  bool DecodePGN127250(std::vector<unsigned char> v,  NavData& temp_data);
  bool DecodePGN129540(std::vector<unsigned char> v,  NavData& temp_data);

  // SignalK
  bool DecodeSignalK(std::string s, NavData& temp_data);
  void handleUpdate(wxJSONValue &update, NavData& temp_data);
  void updateItem(wxJSONValue &item, wxString &sfixtime, NavData& temp_data);
  bool updateNavigationPosition(wxJSONValue &value,
                                const wxString &sfixtime, NavData& temp_data);
  void updateNavigationSpeedOverGround(wxJSONValue &value,
                                       const wxString &sfixtime, NavData& temp_data);
  void updateNavigationCourseOverGround(wxJSONValue &value,
                                        const wxString &sfixtime, NavData& temp_data);
  void updateGnssSatellites(wxJSONValue &value, const wxString &sfixtime, NavData& temp_data);
  void updateHeadingTrue(wxJSONValue &value, const wxString &sfixtime, NavData& temp_data);
  void updateHeadingMagnetic(wxJSONValue &value,
                             const wxString &sfixtime, NavData& temp_data);
  void updateMagneticVariance(wxJSONValue &value,
                              const wxString &sfixtime, NavData& temp_data);


};

#endif  // _COMM_DECODER_H