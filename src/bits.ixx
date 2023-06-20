// Written by Gabriel Dos Reis.
// Copyright (C), Gabriel Dos Reis.  All rights reserved.
// See the file LICENSE for license.

module;
import std;

// -- This module provides basic operations for manipulating strongly
// -- typed bit bags; a complement to standard header <bit>.
export module GDR.Bits.Utility;

namespace gdr::bits {
    // -- A concept that holds for enumeration type. 
    export template<typename T>
    concept EnumType = std::is_enum_v<T>;

    // -- Retrieve the underlying numerical representation of an enummeration value.
    export template<EnumType T>
    constexpr auto rep(T t)
    {
        return static_cast<std::underlying_type_t<T>>(t);
    }

    // -- Same as `rep()`, except the as bag of bits, i.e. unsigned type.
    export template<EnumType T>
    constexpr auto as_bits(T t)
    {
        using S = std::make_unsigned_t<std::underlying_type_t<T>>;
        return static_cast<S>(rep(t));
    }

    // -- Bit mask operations on bitmask enums, sequestered in a dedicated namespace.
    namespace operations {
        export template<EnumType T>
        constexpr T operator&(T x, T y)
        {
            return static_cast<T>(as_bits(x) & as_bits(y));
        }

        export template<EnumType T>
        constexpr T operator|(T x, T y)
        {
            return static_cast<T>(as_bits(x) | as_bits(y));
        }

        export template<EnumType T>
        constexpr T operator^(T x, T y)
        {
            return static_cast<T>(as_bits(x) ^ as_bits(y));
        }

        export template<EnumType T>
        constexpr T operator~(T x)
        {
            return static_cast<T>(~as_bits(x));
        }
    }
}