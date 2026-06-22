float score(coordinate_t pos) {
    float r_squared = (pos.x * pos.x) + (pos.y * pos.y);
    
    if (r_squared <= 1.0F)   return 10.0F;
    if (r_squared <= 25.0F)  return 5.0F;
    if (r_squared <= 100.0F) return 1.0F;
    
    return 0.0F;
}
// sqrt fucntion requre more calculation its better to do not use it