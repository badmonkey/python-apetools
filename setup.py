from setuptools import setup, Extension

project = setup(
    setup_requires="setupmeta",
    ext_modules=[
        Extension(
            "apetools._libgit",
            ["c_src/libgit2ext.c", "c_src/repository_type.c", "c_src/util.c"],
            libraries=["git2"],
            include_dirs=["/usr/include"],
            library_dirs=["/usr/lib"],
            py_limited_api=True,
        )
    ],
).metadata.__dict__
