/*
 * This file is part of Quantum++.
 *
 * Copyright (c) 2013 - 2021 softwareQ Inc. All rights reserved.
 *
 * MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

// IMPORTANT: instantiation of global singletons
// Init, Codes, Gates, States and RandomDevices
//
// Any additional singletons should be instantiated here
// Includes all necessary headers (except "matlab.hpp")
// ALWAYS include it in main.cpp

/**
 * \file qpp.h
 * \brief Quantum++ main header file, includes all other necessary headers
 */

#ifndef QPP_H_
#define QPP_H_

// silence bogus warning -Wunused-variable for singletons
#if (__GNUC__ || __clang__)
#define QPP_UNUSED_ __attribute__((unused))
#else
#define QPP_UNUSED_
#endif

// standard C++ library headers
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

// Eigen headers
#include <Eigen/Dense>
#include <Eigen/SVD>

// Quantum++ headers

// do not change the order in this group, inter-dependencies
#include "types.hpp"
#include "classes/exception.hpp"
#include "constants.hpp"
#include "traits.hpp"
#include "classes/idisplay.hpp"
#include "internal/util.hpp"
#include "internal/classes/iomanip.hpp"
#include "input_output.hpp"

// do not change the order in this group, inter-dependencies
#include "internal/classes/singleton.hpp"
#include "classes/random_devices.hpp"
#include "random.hpp"
#include "number_theory.hpp"

// do not change the order in this group, inter-dependencies
#include "functions.hpp"
#include "classes/init.hpp"
#include "classes/codes.hpp"
#include "classes/gates.hpp"
#include "classes/states.hpp"

// do not change the order in this group, inter-dependencies
#include "statistics.hpp"
#include "operations.hpp"
#include "entropies.hpp"
#include "entanglement.hpp"

// the ones below can be in any order, no inter-dependencies
#include "instruments.hpp"
#include "classes/layouts.hpp"
#include "classes/noise.hpp"
#include "classes/reversible.hpp"
#include "classes/timer.hpp"
#include "classes/circuits/circuits.hpp"
#include "classes/circuits/engines.hpp"

// do not change the order in this group, inter-dependencies
#include "qasmtools/parser/parser.hpp"
#include "qasm/qasm.hpp"

/**
 * \namespace qpp
 * \brief Quantum++ main namespace
 */
namespace qpp {
/**
 * \brief qpp::Init const Singleton
 *
 * Additional initializations/cleanups, see the class qpp::Init
 */
static const Init& init QPP_UNUSED_ = Init::get_no_thread_local_instance();

/**
 * \brief qpp::Codes const Singleton
 *
 * Initializes the codes, see the class qpp::Codes
 */
static const Codes& codes QPP_UNUSED_ = Codes::get_no_thread_local_instance();

/**
 * \brief qpp::Gates const Singleton
 *
 * Initializes the gates, see the class qpp::Gates
 */
static const Gates& gt QPP_UNUSED_ = Gates::get_no_thread_local_instance();

/**
 * \brief qpp::States const Singleton
 *
 * Initializes the states, see the class qpp::States
 */
static const States& st QPP_UNUSED_ = States::get_no_thread_local_instance();

/**
 * \brief qpp::RandomDevices Singleton
 *
 * Initializes the random devices, see the class qpp::RandomDevices
 *
 * \note If the compiler supports thread_local, has thread_local storage
 * duration, due to mutability of its public member std::mt19937 and possible
 * data races
 */

#ifndef NO_THREAD_LOCAL_
thread_local
#endif
    static RandomDevices& rdevs QPP_UNUSED_ = RandomDevices::get_instance();

/**
 * \namespace qpp::obsolete
 * \brief Obsolete/deprecated code, may be removed without notice in future
 * releases
 */
namespace obsolete {} /* namespace obsolete */

} /* namespace qpp */

#endif /* QPP_H_ */
