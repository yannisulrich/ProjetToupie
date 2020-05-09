SET( Core_SRCS
        Common/Assimp.cpp
        )
SET( Logging_SRCS
        ../assimp/DefaultLogger.hpp
        ../assimp/LogStream.hpp
        ../assimp/Logger.hpp
        ../assimp/NullLogger.hpp
        Common/Win32DebugLogStream.h
        Common/DefaultLogger.cpp
        Common/FileLogStream.h
        Common/StdOStreamLogStream.h
        )
SET( Common_SRCS
        Common/BaseImporter.cpp
        Common/BaseProcess.cpp
        Common/BaseProcess.h
        Common/Importer.h
        Common/ScenePrivate.h
        Common/PostStepRegistry.cpp
        Common/ImporterRegistry.cpp
        Common/DefaultProgressHandler.h
        Common/DefaultIOStream.cpp
        Common/DefaultIOSystem.cpp
        Common/ZipArchiveIOSystem.cpp
        Common/PolyTools.h
        Common/Importer.cpp
        Common/IFF.h
        Common/SGSpatialSort.cpp
        Common/VertexTriangleAdjacency.cpp
        Common/VertexTriangleAdjacency.h
        Common/SpatialSort.cpp
        Common/SceneCombiner.cpp
        Common/ScenePreprocessor.cpp
        Common/ScenePreprocessor.h
        Common/SkeletonMeshBuilder.cpp
        Common/StandardShapes.cpp
        Common/TargetAnimation.cpp
        Common/TargetAnimation.h
        Common/RemoveComments.cpp
        Common/Subdivision.cpp
        Common/scene.cpp
        Common/Bitmap.cpp
        Common/Version.cpp
        Common/CreateAnimMesh.cpp
        Common/simd.h
        Common/simd.cpp
        Common/material.cpp
        )


add_library(MyAssimp ${Common_SRCS} ${Core_SRCS} ${Logging_SRCS})
target_include_directories(MyAssimp PRIVATE ..)
message("MyAssimp added")