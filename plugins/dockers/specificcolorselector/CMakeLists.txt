set(KRITA_SPECIFICCOLORSELECTOR_SOURCES 
    specificcolorselector.cc 
    specificcolorselector_dock.cc 
    kis_specific_color_selector_widget.cc 
)
add_library(kritaspecificcolorselector MODULE ${KRITA_SPECIFICCOLORSELECTOR_SOURCES})
target_link_libraries(kritaspecificcolorselector kritaui ${OPENEXR_LIBRARIES})
install(TARGETS kritaspecificcolorselector  DESTINATION ${KRITA_PLUGIN_INSTALL_DIR})
