// -*- c++ -*-
//
// Copyright (c) 2015-2016, Andrey Fainer <fandrey@gmx.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef IO_VOXELS_H
#define IO_VOXELS_H

#include <common/interfaces.h>

class VoxelsIOPlugin : public QObject, public MeshIOInterface
{
  Q_OBJECT
  MESHLAB_PLUGIN_IID_EXPORTER( MESH_IO_INTERFACE_IID )
  Q_INTERFACES( MeshIOInterface );

public:
  QList< Format > importFormats() const;
  QList< Format > exportFormats() const;

  virtual void GetExportMaskCapability(QString &format, int &capability, int &defaultBits) const;

  virtual bool open(const QString &formatName, const QString &fileName, MeshModel &m, int& mask, const RichParameterSet & par,vcg::CallBackPos *cb=0, QWidget *parent=0);
  virtual bool save(const QString &formatName, const QString &fileName, MeshModel &m, const int mask,const RichParameterSet & par, vcg::CallBackPos *cb = 0, QWidget *parent = 0);
};

#endif
