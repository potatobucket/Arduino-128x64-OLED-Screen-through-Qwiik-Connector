"""Custom exceptions for automatically converting bitmap images to OLED-readable format."""

class TooBig(Exception):
    """A given dimension of this picture is too big for the OLED display."""
