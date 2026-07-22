cmake_minimum_required(VERSION 3.19)
project(SpotifyGUI LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(SpotifyGUI
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    AbstractRepository.h Account.cpp Account.h AccountRepository.h Album.cpp Album.h AlbumRepository.cpp AlbumRepository.h ArtistRepository.cpp ArtistRepository.h ListenerRepository.cpp ListenerRepository.h Playlist.cpp Playlist.h PlaylistRepository.cpp PlaylistRepository.h Song.cpp Song.h SongRepository.cpp SongRepository.h SpotifySystem.cpp SpotifySystem.h
)

target_link_libraries(SpotifyGUI
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS SpotifyGUI
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET SpotifyGUI
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
