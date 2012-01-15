// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "port/port_boost.h"

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include "util/logging.h"

namespace leveldb {
namespace port {

Mutex::Mutex() {}

Mutex::~Mutex() {}

void Mutex::Lock() { mu_.lock(); }

void Mutex::Unlock() { mu_.unlock(); }

CondVar::CondVar(Mutex* mu)
    : mu_(mu) {
}

CondVar::~CondVar() {}

void CondVar::Wait() {
  cv_.wait(boost::unique_lock<boost::mutex>(mu_->mu_));
}

void CondVar::Signal() {
  cv_.notify_one();
}

void CondVar::SignalAll() {
  cv_.notify_all();
}

}  // namespace port
}  // namespace leveldb
