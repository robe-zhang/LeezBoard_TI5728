
add_library(Qt5:: MODULE IMPORTED)

_populate_WaylandCompositor_plugin_properties( RELEASE "wayland-graphics-integration-server/libwayland-egl.so")

list(APPEND Qt5WaylandCompositor_PLUGINS Qt5::)
