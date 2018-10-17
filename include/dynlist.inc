# DynList GNU AS Macros
# Helper macro that has all unnecessary fields set to a default value
.macro DynListCmd cmd, w1=0, w2=0, f1=0.0, f2=0.0, f3=0.0
    .4byte \cmd, \w1, \w2
    .float \f1, \f2, \f3
.endm

# Object type constants for dynlist make object command
.set D_CAR_DYNAMICS, 0
.set D_NET, 1
.set D_JOINT, 2
.set D_ANOTHER_JOINT, 3
.set D_CAMERA, 4
.set D_VERTEX, 5
.set D_FACE, 6
.set D_PLANE, 7
.set D_BONE, 8
.set D_MATERIAL, 9
.set D_SHAPE, 10
.set D_GADGET, 11
.set D_LABEL, 12
.set D_VIEW, 13
.set D_ANIMATOR, 14
.set D_DIFF_GRP, 15
.set D_PARTICLE, 16
.set D_LIGHT, 17
.set D_GROUP, 18

# Paramters that can be set by SetParamPtr command
.set PARAM_OBJ_VTX, 1
.set PARAM_CHAR_PTR, 5

##### DynList Command Macros #####
# Necessary start command for the dynlist. List will not process otherwise.
.macro StartList
    DynListCmd 53716
.endm

# Necessary stop command for the dynlist.
.macro StopList
    DynListCmd 58
.endm

# Subsequent dynobj ids should be treated as ints, not as C string pointers.
.macro UseIntId w2
    DynListCmd 0,, \w2
.endm

# Set the initial position of the current object
# Supported Objs: joints, particles, nets, vertices, cameras
.macro SetInitialPosition x, y, z
    DynListCmd 1,,, \x, \y, \z
.endm

# Set the relative position of the current object
# Supported Objs: joints, particles, vertices, cameras, labels
.macro SetRelativePosition x, y, z
    DynListCmd 2,,, \x, \y, \z
.endm

# Set the world position of the current object
# Supported Objs: joints, nets, vertices, cameras, gadgets, views
.macro SetWorldPosition x, y, z
    DynListCmd 3,,, \x, \y, \z
.endm

# Set the normal of the current object
# Supported Objs: vertices
.macro SetNormal x, y, z
    DynListCmd 4,,, \x, \y, \z
.endm

# Set the scale of the current object
# Supported Objs: joints, particles, nets, gadgets, views, lights
.macro SetScale x, y, z
    DynListCmd 5,,, \x, \y, \z
.endm

# Set the rotation of the current object
# Supported Objs: joints, nets
.macro SetRotation x, y, z
    DynListCmd 6,,, \x, \y, \z
.endm

# Set the half-word flag in the header of the current dynobj
# Supported Objs: all
.macro SetHeaderFlag w2
    DynListCmd 7,, \w2
.endm

# Set the bits in an object specific flag with the provided flag
# Supported Objs: bones, joints, particles, shapes, nets, cameras, views, lights
.macro SetFlag w2
    DynListCmd 8,, \w2
.endm

# Clear the bits in an object specific flag with the provided flag
# Supported Objs: bones, joints, particles, nets, cameras
.macro ClearFlag w2
    DynListCmd 9,, \w2
.endm

# Set the friction vector of a Joint
# Supported Objs: joints
.macro SetFriction x, y, z
    DynListCmd 10,,, \x, \y, \z
.endm

# Set the spring float of a Bone
# Supported Objs: bones
.macro SetSpring x
    DynListCmd 11,,, \x
.endm

# Jump to pointed dynlist. Once that list has finished processing, flow returns to current list.
.macro JumpToList w1
    DynListCmd 12, \w1
.endm

# Store either the enumerated "colour" number in an object, or the RGB float values the number refers to
# Supported Objs: joints, particles, nets, faces, gadgets
.macro SetColourNum w2
    DynListCmd 13,, \w2
.endm

# Make an object of the specified type and id, and add that object to the dynobj pool.
.macro MakeDynObj w1, w2
    DynListCmd 15, \w2, \w1
.endm

# Make a group object that will contain all subsequently created objects once the EndGroup command is called.
.macro StartGroup w1
    DynListCmd 16, \w1
.endm

# Collect all objects created after the StartGroup command with the same id.
# Supported Objs: groups
.macro EndGroup w1
    DynListCmd 17, \w1
.endm

# Add the current dyn object to the Group with the called ID
# Supported Objs: groups
.macro AddToGroup w1
    DynListCmd 18, \w1
.endm

# Set an object specific type flag.
# Supported Objs: groups, joints, particles, nets, materials, gadgets
.macro SetType w2
    DynListCmd 19,, \w2
.endm

# Assign the material Group ID to the current dynobj Shape and check the Shape
# Supported Objs: shapes
.macro SetMaterialGroup w1
    DynListCmd 20, \w1
.endm

# Attach Group ID to the current dynobj
# Supported Objs: shapes, nets, gadgets, animators
.macro SetNodeGroup w1
    DynListCmd 21, \w1
.endm

# Set the skin group of the current Net dynobj with the vertices from Shape ID
# Supported Objs: nets
.macro SetSkinShape w1
    DynListCmd 22, \w1
.endm

# Set the plane group ID of the current dynobj
# Supported Objs: shapes, nets
.macro SetPlaneGroup w1
    DynListCmd 23, \w1
.endm

# Set the current dynobj's shape pointer by dereferencing the ptr ptr
# Supported Objs: bones, joints, particles, nets, gadgets, lights
.macro SetShapePtrPtr w1
    DynListCmd 24, \w1
.endm

# Set the current dynobj's shape pointer to Shape ID
# Supported Objs: bones, joints, particles, nets, gadgets
.macro SetShapePtr w1
    DynListCmd 25, \w1
.endm

# Set offset of the connected shape
# Supported Objs: joints
.macro SetShapeOffset x, y, z
    DynListCmd 26,,, \x, \y, \z
.endm

# Set the center of gravity of the current Net object
# Supported Objs: nets
.macro SetCenterOfGravity x, y, z
    DynListCmd 27,,, \x, \y, \z
.endm

# Link Object ID to the current dynobj
# Supported Objs: groups, bones, faces, cameras, views, labels, animators
.macro LinkWith w1
    DynListCmd 28, \w1
.endm

# Link Object pointer to the current dynobj
# Supported Objs: groups, bones, faces, cameras, views, labels, animators
.macro LinkWithPtr w1
    DynListCmd 29, \w1
.endm

# Set Object ID as the current dynobj
# Supported Objs: all
.macro UseObj w1
    DynListCmd 30, \w1
.endm

# Set the current Net object's control type field
# Supported Objs: nets
.macro SetControlType w2
    DynListCmd 31,, \w2
.endm

# Set the weight of the current Joint object with ID and VALUE
# Supported Objs: joints
.macro SetSkinWeight w2, x
    DynListCmd 32,, \w2, \x
.endm

# Set the ambient color of the current Material object
# Supported Objs: materials
.macro SetAmbient x, y, z
    DynListCmd 33,,, \x, \y, \z
.endm

# Set the diffuse color of the current Material or Light object
# Supported Objs: materials, lights
.macro SetDiffuse x, y, z
    DynListCmd 34,,, \x, \y, \z
.endm

# Set the numerical Object ID field (not dynobj id)
# Supported Objs: joints, vertices, materials, lights
.macro SetId w2
    DynListCmd 35,, \w2
.endm

# Set the material id of the current Face
# Supported Objs: faces
.macro SetMaterial w1, w2
    DynListCmd 36, \w1, \w2
.endm

# Map Materials from Group ID to the current Group obj
# Supported Objs: groups
.macro MapMaterials w1
    DynListCmd 37, \w1
.endm

# Map vertices from Group ID to the current Group obj, and correct any vertex indices to pointers
# Supported Objs: groups
.macro MapVertices w1
    DynListCmd 38, \w1
.endm

# Stub command
# Supported Objs: joints
.macro Attach w1
    DynListCmd 39, \w1
.endm

# Attach the current dynobj with modifications made by FLAG to Object ID
# Supported Objs: joints, particles, nets, animators
.macro AttachTo w1, w2
    DynListCmd 40, \w2, \w1
.endm

# Set the offset of the attached object for the current dynobj
# Supported Objs: joints, particles, nets
.macro SetAttachOffset x, y, z
    DynListCmd 41,,, \x, \y, \z
.endm

# Copy the C-string pointed to by PTR to the dynobj id buf
.macro CopyStrToIdBuf w1
    DynListCmd 43, \w1
.endm

# Set float paramter PARAM to VALUE. TODO: Ennumerate parameters
# Supported Objs: shapes, vertices, gadgets
.macro SetParamF w2, x
    DynListCmd 44,, \w2, \x
.endm

# Set pointer paramter PARAM to PTR
# Supported Objs: faces, views, labels
.macro SetParamPtr w1, w2
    DynListCmd 45, \w2, \w1
.endm

# Create a Net and a subgroup with ID. ARG1 is not used
.macro MakeNetWithSubGroup w1, w2
    DynListCmd 46, \w2, \w1
.endm

# Make Joint ID and attach the Net created with "MakeNetWithSubGroup". ARG1 is not used
.macro AttachNetToJoint w1, w2
    DynListCmd 47, \w2, \w1
.endm

# Ends a net sub-Group ID that was created with "MakeNetWithSubGroup"
.macro EndNetSubGroup w1
    DynListCmd 48, \w1
.endm

# Add a Vertex dynobj
.macro MakeVertex x, y, z
    DynListCmd 49,,, \x, \y, \z
.endm

# Add a ValPtr dynobj
.macro MakeValPtr id, flags, type, offset
    DynListCmd 50, \id, \type, \offset, \flags
.endm

# Add the texture pointed to by PTR to the current dynobj
# Supported Objs: materials
.macro UseTexture w2
    DynListCmd 52,, \w2
.endm

# Set the S and T values of the current dynobj
# Supported Objs: vertices
.macro SetTextureST x, y
    DynListCmd 53,,, \x, \y
.endm

# Make a new Net from Shape ID
.macro MakeNetFromShapeId w1
    DynListCmd 54, \w1
.endm

# Make a new Net from Shape double pointer PTR
.macro MakeNetFromShapeDblPtr w1
    DynListCmd 55, \w1
.endm
