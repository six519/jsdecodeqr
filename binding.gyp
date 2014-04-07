{
  "targets": [
    {
      "target_name": "decode",
      "sources": [ "src/decode.cc" ],
      'cflags!': ['-fno-rtti'],
      'cflags_cc!': ['-fno-rtti'],
      'cflags': ['-fexceptions'],
      'cflags_cc': ['-fexceptions'],
      'link_settings': {
          'libraries': [
              '-ldecodeqr', '-lopencv_core', '-lopencv_highgui'
          ]
      },
      'include_dirs': [
      	"/usr/include/opencv"
      ]
    }
  ]
}