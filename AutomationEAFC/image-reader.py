from pdf2image import convert_from_path
import pytesseract
from PIL import Image

# Path to your PDF file
pdf_path = './SimulationEAFC.pdf'

# Convert PDF pages to images
images = convert_from_path(pdf_path)

# Save images to files and store their paths in a list
image_paths = []
for i, image in enumerate(images):
    image_path = f'page_{i+1}.png'
    image.save(image_path, 'PNG')
    image_paths.append(image_path)

# Function to perform OCR on an image and extract text
def ocr_image(image_path):
    image = Image.open(image_path)
    text = pytesseract.image_to_string(image)
    return text

# Performing OCR on the images
ocr_results = [ocr_image(image_path) for image_path in image_paths]

# Print the OCR results from the first image as an example
print(ocr_results[0])