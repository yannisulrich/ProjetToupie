

add_subdirectory(FileViewer)
add_subdirectory(TextViewer)
add_subdirectory(OpenGLViewer)

add_library(GraphicsCore Dessinable.h SupportADessin.h)
target_include_directories(GraphicsCore PUBLIC ..)