project(SvgTextTool)

set(CMAKE_AUTORCC ON)

set (SvgTextTool_SRCS
    BasicXMLSyntaxHighlighter.cpp
    Plugin.cpp
    SvgTextChangeCommand.cpp
    SvgTextEditor.cpp
    SvgTextTool.cpp
    SvgTextToolFactory.cpp
    svgtexttool.qrc
    kis_font_family_combo_box.cpp
)

ki18n_wrap_ui(SvgTextTool_SRCS 
    WdgSvgTextEditor.ui
    WdgSvgTextSettings.ui
)

install( FILES
    SvgTextTool.action
    DESTINATION  ${DATA_INSTALL_DIR}/krita/actions
)


add_library(krita_tool_svgtext MODULE ${SvgTextTool_SRCS})
target_link_libraries(krita_tool_svgtext kritaui KF5::I18n)
install(TARGETS krita_tool_svgtext DESTINATION ${KRITA_PLUGIN_INSTALL_DIR})

add_executable(svgtexttool ${SvgTextTool_SRCS} main.cpp)
target_link_libraries(svgtexttool kritaui KF5::I18n)
