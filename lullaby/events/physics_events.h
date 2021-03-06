/*
Copyright 2017-2019 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS-IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef LULLABY_EVENTS_PHYSICS_EVENTS_H_
#define LULLABY_EVENTS_PHYSICS_EVENTS_H_

#include "lullaby/util/entity.h"
#include "lullaby/util/typeid.h"

namespace lull {

// This event will only be sent locally.
struct EnterPhysicsContactEvent {
  EnterPhysicsContactEvent() {}
  explicit EnterPhysicsContactEvent(Entity e) : other(e) {}
  Entity other = kNullEntity;

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&other, ConstHash("other"));
  }
};

// This event will only be sent locally.
struct ExitPhysicsContactEvent {
  ExitPhysicsContactEvent() {}
  explicit ExitPhysicsContactEvent(Entity e) : other(e) {}
  Entity other = kNullEntity;

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&other, ConstHash("other"));
  }
};

}  // namespace lull

LULLABY_SETUP_TYPEID(lull::EnterPhysicsContactEvent);
LULLABY_SETUP_TYPEID(lull::ExitPhysicsContactEvent);

#endif  // LULLABY_EVENTS_PHYSICS_EVENTS_H_
