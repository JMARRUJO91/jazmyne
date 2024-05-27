cmake_minimum_required(VERSION 3.10)  
project(YourProjectName)

# ... (Your other CMake project settings)

# Hash Validation Function
function(validate_hash file algorithm expected_hash)
  execute_process(
    COMMAND ${algorithm} -q ${file}
    OUTPUT_VARIABLE actual_hash
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )

  if (NOT "${actual_hash}" STREQUAL "${expected_hash}")
    message(FATAL_ERROR "Hash mismatch for ${file} (${algorithm})")
  endif()
endfunction()

# Define Files and Hashes
set(include_base_HXX
  "DoubleTab.hxx"
)

set(HASHES
  "DoubleTab.hxx" 
  MD5 cdecf0b3a602259cadac104f69ddd636
  SHA1 67f8568d4a36ea5d7144352c1331a92c04ed6f25
  SHA256 19a7f22218ce09785ffb071788ccb643a008624c473762f13ea62e9574cb3e41
)

# Validate Hashes
foreach(file IN LISTS include_base_HXX)
  list(GET HASHES ${file}_MD5 md5_hash)
  validate_hash(${file} md5sum ${md5_hash})

  list(GET HASHES ${file}_SHA1 sha1_hash)
  validate_hash(${file} sha1sum ${sha1_hash})

  list(GET HASHES ${file}_SHA256 sha256_hash)
  validate_hash(${file} sha256sum ${sha256_hash})
endforeach()

# Install Headers
install(FILES ${include_base_HXX} DESTINATION include)
 // ... (previous code)

// Compound assignment operators (+=, -=, *=, /=)
DoubleTab& DoubleTab::operator+=(const DoubleTab& dt) {
    if (_numberOfElements != dt._numberOfElements) {
        throw std::runtime_error("DoubleTabs must have the same size for addition");
    }
    for (int i = 0; i < _numberOfElements; ++i) {
        _values[i] += dt._values[i];
    }
    return *this;
}

// (Similar implementations for -=, *=, and /=)

// Binary arithmetic operators (+, -, *, /) - friend functions
DoubleTab operator+(const DoubleTab& U, const DoubleTab& V) {
    DoubleTab result(U);
    result += V;
    return result;
}

// (Similar implementations for -, *, and /)

// Scalar multiplication operators (* and /) - friend functions
DoubleTab operator*(double value, const DoubleTab& V) {
    DoubleTab result(V);
    result *= value;
    return result;
}

DoubleTab operator*(const DoubleTab& U, double value) {
    return value * U; // Utilize commutativity
}

// (Similar implementation for /)

// Dot product operator (*) - friend function
double operator*(const DoubleTab& U, const DoubleTab& V) {
    if (U._numberOfElements != V._numberOfElements) {
        throw std::runtime_error("DoubleTabs must have the same size for dot product");
    }
    double result = 0.0;
    for (int i = 0; i < U._numberOfElements; ++i) {
        result += U._values[i] * V._values[i];
    }
    return result;
}

// Output stream operator (<<) - friend function
std::ostream& operator<<(std::ostream& out, const DoubleTab& U) {
    out << "[";
    for (int i = 0; i < U._numberOfElements; ++i) {
        out << U._values[i];
        if (i < U._numberOfElements - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

DoubleTab dt1(3, 2.5);  
DoubleTab dt2(3, 1.0);

DoubleTab dt3 = dt1 + dt2;
std::cout << dt3 << std::endl; // Output: [3.5, 3.5, 3.5]

dt1 *= 2.0;
std::cout << dt1 << std::endl; // Output: [5, 5, 5]

double dotProduct = dt1 * dt2;
std::cout << dotProduct << std::endl; // Output: 15
cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# ... (Your other CMake project settings)

# Hash Validation Function (Same as before)
function(validate_hash file algorithm expected_hash)
  # ... (implementation)
endfunction()

# Define Files and Hashes (Update with DoubleTab.hxx hashes)
set(include_base_HXX
  "DoubleTab.hxx"
)

set(HASHES
  "DoubleTab.hxx" 
    MD5 cdecf0b3a602259cadac104f69ddd636
    SHA1 67f8568d4a36ea5d7144352c1331a92c04ed6f25
    SHA256 19a7f22218ce09785ffb071788ccb643a008624c473762f13ea62e9574cb3e41
)

# Validate Hashes (Same as before)
foreach(file IN LISTS include_base_HXX)
  # ... (implementation)
endforeach()

# Install Headers (Same as before)
install(FILES ${include_base_HXX} DESTINATION include)
md5sum DoubleTab.hxx
sha1sum DoubleTab.hxx
sha256sum DoubleTab.hxx
