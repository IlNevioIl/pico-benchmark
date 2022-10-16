cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(pico-benchmark)

pico_sdk_init()

add_executable(benchmark
    benchmark.c
    utils.c
)   

target_link_libraries(benchmark
    pico_multicore
    pico_stdlib
    hardware_adc
)

pico_enable_stdio_usb(benchmark 1)
pico_enable_stdio_uart(benchmark 0)

pico_add_extra_outputs(benchmark)