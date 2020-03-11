{
  "targets": [
    # {
    #   "target_name": "greet",
    #   "cflags!": [ "-fno-exceptions" ],
    #   "cflags_cc!": [ "-fno-exceptions" ],
    #   "sources": [
    #     "./src/greeting.cpp",
    #     "./src/index.cpp"
    #   ],
    #   "include_dirs": [
    #     "<!@(node -p  \"require('node-addon-api').include\")"
    #   ],
    #   "defines": [
    #     "NAPI_DISABLE_CPP_EXCEPTIONS"
    #   ],
    # },
    # {
    #   "target_name": "callback",
    #   "cflags!": [ "-fno-exceptions" ],
    #   "cflags_cc!": [ "-fno-exceptions" ],
    #   "sources": [
    #     "./src/callback.cc",
    #   ],
    #   "include_dirs": [
    #     "<!@(node -p  \"require('node-addon-api').include\")"
    #   ],
    #   "defines": [
    #     "NAPI_DISABLE_CPP_EXCEPTIONS"
    #   ],
    # },
    {
      "target_name": "aclas-sdk",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "./src/aclas-sdk.cc",
      ],
      "include_dirs": [
        "<!@(node -p  \"require('node-addon-api').include\")"
      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS"
      ],
    },
    # {
    #   "target_name": "object-wrap",
    #   "cflags!": [ "-fno-exceptions" ],
    #   "cflags_cc!": [ "-fno-exceptions" ],
    #   "sources": [
    #     "./src/object_wrap/myobject.cc",
    #     # "./src/object_wrap/addon.cc",
    #   ],
    #   "include_dirs": [
    #     "<!@(node -p  \"require('node-addon-api').include\")"
    #   ],
    #   "defines": [
    #     "NAPI_DISABLE_CPP_EXCEPTIONS"
    #   ],
    # },
  ]
}