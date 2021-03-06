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

#ifndef LULLABY_EVENTS_ENTITY_EVENTS_H_
#define LULLABY_EVENTS_ENTITY_EVENTS_H_

#include "lullaby/util/entity.h"
#include "lullaby/util/typeid.h"

namespace lull {

// Invokes TransformSystem::Enable(entity)
struct EnableEvent {
  EnableEvent() {}
  explicit EnableEvent(Entity entity) : entity(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
  }

  Entity entity = kNullEntity;
};

// Invokes TransformSystem::Disable(entity)
struct DisableEvent {
  DisableEvent() {}
  explicit DisableEvent(Entity entity) : entity(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
  }

  Entity entity = kNullEntity;
};

// Invokes TransformSystem::AddChild(entity, child,
// kPreserveParentToEntityTransform)
struct AddChildEvent {
  AddChildEvent() {}
  AddChildEvent(Entity entity, Entity child) : entity(entity), child(child) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
    archive(&child, ConstHash("child"));
  }

  Entity entity = kNullEntity;
  Entity child = kNullEntity;
};

// Invokes TransformSystem::AddChild(entity, child,
// kPreserveWorldToEntityTransform)
struct AddChildPreserveWorldToEntityTransformEvent {
  AddChildPreserveWorldToEntityTransformEvent() {}
  AddChildPreserveWorldToEntityTransformEvent(Entity entity, Entity child)
      : entity(entity), child(child) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
    archive(&child, ConstHash("child"));
  }

  Entity entity = kNullEntity;
  Entity child = kNullEntity;
};

struct OnDisabledEvent {
  OnDisabledEvent() {}
  explicit OnDisabledEvent(Entity entity) : target(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&target, ConstHash("target"));
  }

  Entity target = kNullEntity;
};

struct OnEnabledEvent {
  OnEnabledEvent() {}
  explicit OnEnabledEvent(Entity entity) : target(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&target, ConstHash("target"));
  }

  Entity target = kNullEntity;
};

struct ParentChangedEvent {
  ParentChangedEvent() {}
  ParentChangedEvent(Entity entity, Entity old_parent, Entity new_parent)
      : target(entity), old_parent(old_parent), new_parent(new_parent) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&target, ConstHash("target"));
    archive(&old_parent, ConstHash("old_parent"));
    archive(&new_parent, ConstHash("new_parent"));
  }

  Entity target = kNullEntity;
  Entity old_parent = kNullEntity;
  Entity new_parent = kNullEntity;
};

// Like ParentChangedEvent, this is sent whenever a parent-child relationship
// changes. However, this event is sent immediately (without being queued in the
// dispatcher). Listener callbacks can be invoked at potentially unsafe times
// (eg within PostCreateInit or Destroy), so users of this event should take
// precautions such as verifying the existence of specified entities' data.
struct ParentChangedImmediateEvent : public ParentChangedEvent {
  ParentChangedImmediateEvent() {}
  ParentChangedImmediateEvent(Entity entity, Entity old_parent,
                              Entity new_parent)
      : ParentChangedEvent(entity, old_parent, new_parent) {}
};

struct ChildAddedEvent {
  ChildAddedEvent() {}
  ChildAddedEvent(Entity parent, Entity child) : target(parent), child(child) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&target, ConstHash("target"));
    archive(&child, ConstHash("child"));
  }

  Entity target = kNullEntity;
  Entity child = kNullEntity;
};

struct ChildRemovedEvent {
  ChildRemovedEvent() {}
  ChildRemovedEvent(Entity parent, Entity child)
      : target(parent), child(child) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&target, ConstHash("target"));
    archive(&child, ConstHash("child"));
  }

  Entity target = kNullEntity;
  Entity child = kNullEntity;
};

// The entity |child| has been moved from |old_index| to |new_index| within the
// array of children of |parent|.
struct ChildIndexChangedEvent {
  ChildIndexChangedEvent() {}
  ChildIndexChangedEvent(Entity parent, Entity child, size_t old_index,
                         size_t new_index)
      : target(parent),
        child(child),
        old_index(old_index),
        new_index(new_index) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&target, ConstHash("target"));
    archive(&child, ConstHash("child"));
    archive(&old_index, ConstHash("old_index"));
    archive(&new_index, ConstHash("new_index"));
  }

  Entity target = kNullEntity;
  Entity child = kNullEntity;
  size_t old_index = 0;
  size_t new_index = 0;
};

// Like ChildIndexChangedEvent, this is sent whenever a child's index has
// changed. However, this event is sent immediately (without being queued in the
// dispatcher). Listener callbacks can be invoked at potentially unsafe times
// (eg within PostCreateInit or Destroy), so users of this event should take
// precautions such as verifying the existence of specified entities' data.
struct ChildIndexChangedImmediateEvent : public ChildIndexChangedEvent {
  ChildIndexChangedImmediateEvent() {}
  ChildIndexChangedImmediateEvent(Entity parent, Entity child, size_t old_index,
                                  size_t new_index)
      : ChildIndexChangedEvent(parent, child, old_index, new_index) {}
};

struct AabbChangedEvent {
  AabbChangedEvent() {}
  explicit AabbChangedEvent(Entity entity) : target(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&target, ConstHash("target"));
  }

  Entity target = kNullEntity;
};

struct OnInteractionDisabledEvent {
  OnInteractionDisabledEvent() {}
  explicit OnInteractionDisabledEvent(Entity entity) : entity(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
  }

  Entity entity = kNullEntity;
};

struct OnInteractionEnabledEvent {
  OnInteractionEnabledEvent() {}
  explicit OnInteractionEnabledEvent(Entity entity) : entity(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
  }

  Entity entity = kNullEntity;
};

struct DisableCollisionEvent {
  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
  }

  Entity entity = kNullEntity;
};

struct EnableCollisionEvent {
  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
  }

  Entity entity = kNullEntity;
};

// Invokes FollowCameraSystem::Enable(entity)
struct EnableFollowCameraEvent {
  EnableFollowCameraEvent() {}
  explicit EnableFollowCameraEvent(Entity entity) : entity(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
  }

  Entity entity = kNullEntity;
};

// Invokes FollowCameraSystem::Disable(entity)
struct DisableFollowCameraEvent {
  DisableFollowCameraEvent() {}
  explicit DisableFollowCameraEvent(Entity entity) : entity(entity) {}

  template <typename Archive>
  void Serialize(Archive archive) {
    archive(&entity, ConstHash("entity"));
  }

  Entity entity = kNullEntity;
};

}  // namespace lull

LULLABY_SETUP_TYPEID(lull::AabbChangedEvent);
LULLABY_SETUP_TYPEID(lull::AddChildEvent);
LULLABY_SETUP_TYPEID(lull::AddChildPreserveWorldToEntityTransformEvent);
LULLABY_SETUP_TYPEID(lull::ChildAddedEvent);
LULLABY_SETUP_TYPEID(lull::ChildIndexChangedEvent);
LULLABY_SETUP_TYPEID(lull::ChildIndexChangedImmediateEvent);
LULLABY_SETUP_TYPEID(lull::ChildRemovedEvent);
LULLABY_SETUP_TYPEID(lull::DisableCollisionEvent);
LULLABY_SETUP_TYPEID(lull::DisableEvent);
LULLABY_SETUP_TYPEID(lull::DisableFollowCameraEvent);
LULLABY_SETUP_TYPEID(lull::EnableCollisionEvent);
LULLABY_SETUP_TYPEID(lull::EnableEvent);
LULLABY_SETUP_TYPEID(lull::EnableFollowCameraEvent);
LULLABY_SETUP_TYPEID(lull::OnDisabledEvent);
LULLABY_SETUP_TYPEID(lull::OnEnabledEvent);
LULLABY_SETUP_TYPEID(lull::OnInteractionDisabledEvent);
LULLABY_SETUP_TYPEID(lull::OnInteractionEnabledEvent);
LULLABY_SETUP_TYPEID(lull::ParentChangedEvent);
LULLABY_SETUP_TYPEID(lull::ParentChangedImmediateEvent);

#endif  // LULLABY_EVENTS_ENTITY_EVENTS_H_
