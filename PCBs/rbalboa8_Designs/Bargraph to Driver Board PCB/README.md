# PCB Directory

This directory contains all the files necessary for the design and manufacture of printed circuit boards (PCBs) for the projects in this repository.

## Directory Structure

- **schematics/**: Contains schematic files for each project.
  - **project1/**: Schematics for Project 1.
  - **project2/**: Schematics for Project 2.
- **layouts/**: Contains PCB layout files for each project.
  - **project1/**: Layouts for Project 1.
  - **project2/**: Layouts for Project 2.
- **gerbers/**: Contains Gerber files required for PCB manufacturing.
  - **project1/**: Gerber files for Project 1.
  - **project2/**: Gerber files for Project 2.

## Projects Overview

### Project 1

- **Schematics**:
  - Files are located in `pcb/schematics/project1/`
  - Formats: PDF, KiCad (.kicad)
- **Layouts**:
  - Files are located in `pcb/layouts/project1/`
  - Formats: PDF, KiCad PCB (.kicad_pcb)
- **Gerbers**:
  - Files are located in `pcb/gerbers/project1/`
  - Formats: ZIP archive, individual Gerber files (.gtl, .gbl, etc.)

### Project 2

- **Schematics**:
  - Files are located in `pcb/schematics/project2/`
  - Formats: PDF, KiCad (.kicad)
- **Layouts**:
  - Files are located in `pcb/layouts/project2/`
  - Formats: PDF, KiCad PCB (.kicad_pcb)
- **Gerbers**:
  - Files are located in `pcb/gerbers/project2/`
  - Formats: ZIP archive, individual Gerber files (.gtl, .gbl, etc.)

## How to Use These Files

### Viewing and Editing Schematics

1. **Open Schematic Files**:
   - Use KiCad or your preferred EDA tool to open `.kicad` files.
   - View `.pdf` files using any PDF viewer for a quick overview.

2. **Edit Schematics**:
   - Open the `.kicad` files in KiCad to make modifications.

### Viewing and Editing PCB Layouts

1. **Open Layout Files**:
   - Use KiCad or your preferred EDA tool to open `.kicad_pcb` files.
   - View `.pdf` files using any PDF viewer for a quick overview.

2. **Edit Layouts**:
   - Open the `.kicad_pcb` files in KiCad to make modifications.

### Manufacturing PCBs

1. **Gerber Files**:
   - Use the ZIP archive in the `gerbers` directory to send to a PCB manufacturer.
   - Alternatively, upload the individual Gerber files to the manufacturer's website.

2. **Verify Gerbers**:
   - Use a Gerber viewer to verify the files before submission.

## Contribution Guidelines

1. **Updating Files**:
   - Ensure any changes to schematics, layouts, or Gerbers are documented in the respective project's changelog.

2. **Versioning**:
   - Follow semantic versioning when making significant changes to the PCB designs.

## Additional Resources

- [KiCad Documentation](https://kicad.org/help/documentation/)
- [Gerber File Format](https://en.wikipedia.org/wiki/Gerber_format)
- [PCB Manufacturing Guide](https://www.protoexpress.com/blog/pcb-manufacturing-process/)
