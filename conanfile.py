from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMakeDeps, CMakeToolchain


class GrimoireConan(ConanFile):
    name = "Grimoire"
    version = "0.1.0"
    description = "Real-time webcam to ASCII art with truecolor terminal output"

    settings = "os", "compiler", "build_type", "arch"

    def requirements(self):
        # self.requires("opencv/4.13.0")
        self.requires("fmt/10.2.1")
        self.requires("spdlog/1.13.0")

    #def build_requirements(self):

    def layout(self):
        cmake_layout(self);

    def generate(self):
        tc = CMakeToolchain(self);
        tc.generate();

        deps = CMakeDeps(self);
        deps.generate();
