
package(
    default_visibility = ["//visibility:public"],
)

licenses(["notice"])  # Apache 2.0

cc_library(
    name = "flatbuffers",
    srcs = [
        "variant_fb_conversions.cc",
    ],
    hdrs = [
        "common_fb_conversions.h",
        "mathfu_fb_conversions.h",
        "variant_fb_conversions.h",
    ],
    deps = [
        "@flatbuffers//:flatbuffers",
        "//:fbs",
        "//lullaby/modules/input",
        "//lullaby/util:arc",
        "//lullaby/util:color",
        "//lullaby/util:common_types",
        "//lullaby/util:inward_buffer",
        "//lullaby/util:logging",
        "//lullaby/util:math",
        "//lullaby/util:optional",
        "//lullaby/util:variant",
        "@mathfu//:mathfu",
    ],
)
